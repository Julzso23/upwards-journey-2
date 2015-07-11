#include "UJ.h"

UJ::UJ(sf::String title, sf::VideoMode size, bool fullscreen)
	: Game(title, size, fullscreen),
	htmlMenu("main", sf::Vector2u(size.width, size.height)),
	xAxis(ControlSet(sf::Keyboard::Right, &gamepadManager, XBoxAxes::LeftX, true, -1), ControlSet(sf::Keyboard::Left, &gamepadManager, XBoxAxes::LeftX, false, -1), 0.25),
	yAxis(ControlSet(sf::Keyboard::Down, &gamepadManager, XBoxAxes::LeftY, true, -1), ControlSet(sf::Keyboard::Up, &gamepadManager, XBoxAxes::LeftY, false, -1), 0.25)
{
}

void UJ::load()
{
	font.loadFromFile("fonts/Frail-Sans.otf");

	htmlMenu.addJSMethod(Awesomium::WSLit("play"), [&](const Awesomium::JSArray& args){
		paused = false;
		setCursorVisible(false);
	});
	htmlMenu.addJSMethod(Awesomium::WSLit("setResolution"), [&](const Awesomium::JSArray& args){
		setResolution(sf::Vector2u(args[0].ToInteger(), args[1].ToInteger()));
	});
	htmlMenu.addJSMethod(Awesomium::WSLit("toggleFullscreen"), [&](const Awesomium::JSArray& args){
		toggleFullscreen();
	});
	htmlMenu.addJSMethod(Awesomium::WSLit("setPlayerHat"), [&](const Awesomium::JSArray& args){
		player.setHat(Awesomium::ToString(args[0].ToString()));
	});
	htmlMenu.addJSMethod(Awesomium::WSLit("setGamepad"), [&](const Awesomium::JSArray& args){
		gamepadManager.setCurrent(args[0].ToInteger());
	});
	htmlMenu.addJSMethod(Awesomium::WSLit("exit"), [&](const Awesomium::JSArray& args){
		exit();
	});

	htmlMenu.addJSMethodWithReturn(Awesomium::WSLit("getResolutions"), [&](const Awesomium::JSArray& args)
	{
		Awesomium::JSArray jsResolutions;
		std::vector<sf::VideoMode> resolutions = getSupportedResolutions();
		for (std::size_t i = 0; i < resolutions.size(); i++)
		{
			Awesomium::JSArray size;
			size.Push(Awesomium::JSValue(static_cast<int>(resolutions[i].width)));
			size.Push(Awesomium::JSValue(static_cast<int>(resolutions[i].height)));
			jsResolutions.Push(size);
		}
		return jsResolutions;
	});
	htmlMenu.addJSMethodWithReturn(Awesomium::WSLit("getGamepads"), [&](const Awesomium::JSArray& args)
	{
		Awesomium::JSArray jsGamepads;
		std::vector<Gamepad>* gamepads = gamepadManager.getGamepads();
		for (std::size_t i = 0; i < gamepads->size(); i++)
		{
			Awesomium::JSArray gamepad;
			gamepad.Push(Awesomium::JSValue((*gamepads)[i].getId()));
			gamepad.Push(Awesomium::JSValue(Awesomium::WSLit((*gamepads)[i].getIdentification().name.toAnsiString().c_str())));
			jsGamepads.Push(gamepad);
		}
		return jsGamepads;
	});

	std::vector<sf::Keyboard::Key> keys;
	keys.insert(keys.end(), sf::Keyboard::Key::Escape);
	keyCommands.insert(keyCommands.end(), KeyCommand(keys, [&](){
		paused = true;
		setCursorVisible(true);
	}));

	gamepadManager.setCurrent(0);

	dropper.create(6.f, 192, 128);
	obsticles = dropper.getObsticles();

	healthDropper.create(0.2f, "health");
	coinDropper.create(0.4f, "coin");

	hud.setPlayer(&player);

	paused = true;

	//modHandler.load();
}

void UJ::update(float dt)
{
	player.update(dt);

	background.update(dt);

	hud.update();

	//modHandler.update(dt, paused);

	if (!paused)
	{
		player.control(sf::Vector2f(xAxis.getValue(), yAxis.getValue()), dt);
		for (std::size_t i = 0; i < obsticles->size(); i++)
			player.isColliding(&(*obsticles)[i]);

		dropper.update(dt);

		healthDropper.update(dt, &player);
		coinDropper.update(dt, &player);
	}
	else
	{
		htmlMenu.update();
	}
}

void UJ::draw(sf::RenderWindow* window)
{
	window->draw(background);

	window->draw(player);

	window->draw(healthDropper);
	window->draw(coinDropper);
	window->draw(dropper);

	window->draw(hud);

	//modHandler.draw();
}
void UJ::drawUnscaled(sf::RenderWindow* window)
{
	if (paused)
		window->draw(htmlMenu);
}

void UJ::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
{
	if (paused)
		htmlMenu.mousePressed(button, position);

	//modHandler.mousePressed(button, position.x, position.y);
}
void UJ::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
{
	if (paused)
		htmlMenu.mouseReleased(button, position);

	//modHandler.mouseReleased(button, position.x, position.y);
}
void UJ::mouseMoved(int x, int y)
{
	if (paused)
		htmlMenu.mouseMoved(x, y);
}

void UJ::keyPressed(sf::Keyboard::Key key)
{
	for (std::size_t i = 0; i < keyCommands.size(); i++)
		keyCommands[i].keyPressed(key);
}
void UJ::keyReleased(sf::Keyboard::Key key)
{
	for (std::size_t i = 0; i < keyCommands.size(); i++)
		keyCommands[i].keyReleased(key);
}

void UJ::joystickConnected(int id)
{
	gamepadManager.addGamepad(id);
	gamepadManager.setCurrent(0);
	std::vector<Gamepad>* gamepads = gamepadManager.getGamepads();
}
void UJ::joystickDisconnected(int id)
{
	gamepadManager.removeGamepad(id);
}

void UJ::windowResized(sf::Vector2u size)
{
	htmlMenu.windowResized(size);
}

void UJ::onExit()
{
	htmlMenu.onExit();
	//modHandler.onExit();
}