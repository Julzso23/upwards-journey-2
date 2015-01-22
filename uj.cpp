#include "UJ.h"

void UJ::load()
{
	font.loadFromFile("fonts/Frail-Sans.otf");

	mainMenu.addButton(GUI::Button("Play", [&](){setMenu(); }, &font));
	mainMenu.addButton(GUI::Button("Hats", [&](){setMenu(&hatsMenu); }, &font));
	mainMenu.addButton(GUI::Button("Options", [&](){setMenu(&optionsMenu); }, &font));
	mainMenu.addButton(GUI::Button("Exit", [&](){exit(); }, &font));

	hatsMenu.addButton(GUI::Button("None", [&](){player.setHat(""); }, &font));
	hatsMenu.addButton(GUI::Button("Top hat", [&](){player.setHat("top"); }, &font));
	hatsMenu.addButton(GUI::Button("Santa hat", [&](){player.setHat("santa"); }, &font));
	hatsMenu.addButton(GUI::Button("Back", [&](){setMenu(&mainMenu); }, &font));

	optionsMenu.addButton(GUI::Button("Video", [&](){setMenu(&optionsVideoMenu); }, &font));
	optionsMenu.addButton(GUI::Button("Audio", [&](){}, &font));
	optionsMenu.addButton(GUI::Button("Controls", [&](){}, &font));
	optionsMenu.addButton(GUI::Button("Back", [&](){setMenu(&mainMenu); }, &font));

	optionsVideoMenu.addButton(GUI::Button("Resolutions", [&](){setMenu(&optionsVideoResolutionsMenu); }, &font));
	optionsVideoMenu.addButton(GUI::Button("Toggle Fullscreen", [&](){toggleFullscreen(); }, &font));
	optionsVideoMenu.addButton(GUI::Button("Back", [&](){setMenu(&optionsMenu); }, &font));

	for (int i = 0; i < getSupportedResolutions().size(); i++)
	{
		optionsVideoResolutionsMenu.addButton(GUI::Button(std::to_string(getSupportedResolutions()[i].width) + " x " + std::to_string(getSupportedResolutions()[i].height), [&, i](){
			setResolution(sf::Vector2u(getSupportedResolutions()[i].width, getSupportedResolutions()[i].height));
		}, &font));
	}
	optionsVideoResolutionsMenu.addButton(GUI::Button("Back", [&](){setMenu(&optionsVideoMenu); }, &font));

	curMenu = &mainMenu;
	curMenu->show();

	std::vector<sf::Keyboard::Key> keys;
	keys.insert(keys.end(), sf::Keyboard::Key::Escape);
	keyCommands.insert(keyCommands.end(), KeyCommand(keys, [&](){setMenu(&mainMenu);}));

	xAxis.create(ControlSet(sf::Keyboard::Right, 0, sf::Joystick::X, true, -1), ControlSet(sf::Keyboard::Left, 0, sf::Joystick::X, false, -1), 0.25);
	yAxis.create(ControlSet(sf::Keyboard::Down, 0, sf::Joystick::Y, true, -1), ControlSet(sf::Keyboard::Up, 0, sf::Joystick::Y, false, -1), 0.25);

	dropper.create(6.f, 192, 128);
	obsticles = dropper.getObsticles();

	healthDropper.create(0.2f, "health");
	coinDropper.create(0.4f, "coin");

	hud.setPlayer(&player);

	paused = true;
}

void UJ::update(float dt)
{
	player.update(dt);

	background.update(dt);

	hud.update();

	if (!paused)
	{
		player.control(sf::Vector2f(xAxis.getValue(), yAxis.getValue()), dt);
		for (int i = 0; i < obsticles->size(); i++)
			player.isColliding(&(*obsticles)[i]);

		dropper.update(dt);

		healthDropper.update(dt, &player);
		coinDropper.update(dt, &player);
	}
	else
	{
		curMenu->update(dt, mousePos());
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

	window->draw(*curMenu);
}

void UJ::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
{
	curMenu->mousePressed(button, position);
}
void UJ::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
{
	curMenu->mouseReleased(button, position);
}

void UJ::keyPressed(sf::Keyboard::Key key)
{
	for (int i = 0; i < keyCommands.size(); i++)
		keyCommands[i].keyPressed(key);
}
void UJ::keyReleased(sf::Keyboard::Key key)
{
	for (int i = 0; i < keyCommands.size(); i++)
		keyCommands[i].keyReleased(key);
}

void UJ::setMenu()
{
	curMenu->hide();
	paused = false;
	setCursorVisible(false);
}
void UJ::setMenu(GUI::Menu* menu)
{
	curMenu->hide();
	curMenu = menu;
	curMenu->show();
	paused = true;
	setCursorVisible(true);
}