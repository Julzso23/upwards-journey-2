#ifndef GUI_HTMLMENU_H
#define GUI_HTMLMENU_H

#include <SFML\Graphics.hpp>
#include <Awesomium\WebCore.h>
#include <Awesomium\BitmapSurface.h>
#include <Awesomium\STLHelpers.h>

namespace GUI
{
	class HTMLMenu : public sf::Drawable
	{
	private:
		Awesomium::WebCore* webCore;
		Awesomium::WebView* view;
		sf::Texture* texture;
		sf::Sprite sprite;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		HTMLMenu(std::string fileName, sf::Vector2u size);

		void update();

		void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
		void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);
		void mouseMoved(int x, int y);

		void windowResized(sf::Vector2u size);

		void onExit();
	};
}

#endif