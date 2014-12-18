#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "Base.h"
#include <functional>

namespace GUI
{
	class Button : public Base
	{
	private:
		sf::RectangleShape shape;
		sf::Text text;
		GUI::State state;
		std::function<void()> onClick;
	public:
		Button();
		Button(sf::String text, std::function<void()> func, sf::Font* font);
		Button(sf::String text, sf::Vector2f position, sf::Vector2f size);
		void create(sf::String text, sf::Vector2f position, sf::Vector2f size);

		void update(float dt, sf::Vector2i mousePos);

		void draw(sf::RenderWindow* window);

		void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
		void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);

		void setClickFunc(std::function<void()> func);

		void setPos(sf::Vector2f position);
		sf::Vector2f getPos();
	};
}

#endif