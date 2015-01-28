#include "HTMLMenu.h"

namespace GUI
{
	using namespace Awesomium;
	HTMLMenu::HTMLMenu(std::string fileName, sf::Vector2u size)
	{
		webCore = WebCore::Initialize(WebConfig());
		view = webCore->CreateWebView(size.x, size.y);
		std::string path = "file:///html/" + fileName + ".html";
		view->LoadURL(WebURL(WSLit(path.data())));
		view->SetTransparent(true);
		texture = new sf::Texture();
		texture->create(1920, 1080);
		sprite.setTexture(*texture);
		while (view->IsLoading())
			webCore->Update();
		Sleep(300);
		webCore->Update();
	}

	void HTMLMenu::update()
	{
		webCore->Update();
	}

	void HTMLMenu::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
	{
		switch (button)
		{
		case sf::Mouse::Left: view->InjectMouseDown(MouseButton::kMouseButton_Left);
		case sf::Mouse::Middle: view->InjectMouseDown(MouseButton::kMouseButton_Middle);
		case sf::Mouse::Right: view->InjectMouseDown(MouseButton::kMouseButton_Right);
		}
		view->InjectMouseMove(position.x, position.y);
	}
	void HTMLMenu::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
	{
		switch (button)
		{
		case sf::Mouse::Left: view->InjectMouseUp(MouseButton::kMouseButton_Left);
		case sf::Mouse::Middle: view->InjectMouseUp(MouseButton::kMouseButton_Middle);
		case sf::Mouse::Right: view->InjectMouseUp(MouseButton::kMouseButton_Right);
		}
		view->InjectMouseMove(position.x, position.y);
	}
	void HTMLMenu::mouseMoved(int x, int y)
	{
		view->InjectMouseMove(x, y);
	}

	void HTMLMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		BitmapSurface* surface = (BitmapSurface*)view->surface();
		sf::Uint8* buffer = new sf::Uint8[surface->width() * surface->height() * 4];
		surface->CopyTo(buffer, surface->row_span(), 4, true, false);
		texture->update(buffer);
		delete buffer;
		target.draw(sprite, states);
	}

	void HTMLMenu::windowResized(sf::Vector2u size)
	{
		view->Resize(size.x, size.y);
		texture->create(size.x, size.y);
	}

	void HTMLMenu::onExit()
	{
		delete texture;
		view->Destroy();
		WebCore::Shutdown();
	}
}