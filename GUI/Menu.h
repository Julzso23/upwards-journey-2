#ifndef GUI_MENU_H
#define GUI_MENU_H

#include "Button.h"
#include <vector>

namespace GUI
{
	class Menu
	{
	private:
		std::vector<Button> buttons;
		sf::Vector2f position;
		bool enabled;
	public:
		Menu();
		Menu(std::vector<Button> buttons);
		void setButtons(std::vector<Button> buttons);

		void show();
		void hide();

		void update(float dt, sf::Vector2i mousePos);

		void draw(sf::RenderWindow* window);

		void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
		void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);

		void setPos(sf::Vector2f position);
		sf::Vector2f getPos();

		int getHeight();
	};
}

#endif