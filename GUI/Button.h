#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "Base.h"

namespace GUI
{
	class Button : public GUI::Base
	{
	private:
		sf::RectangleShape shape;
		sf::Text text;
		GUI::State state;
	public:
		Button();
		Button(sf::String text, sf::Vector2f postion, sf::Vector2f size);
		sf::RectangleShape getShape();
		sf::Text getDrawText();
	};
}

#endif