#include "Button.h"

namespace GUI
{
	Button::Button()
	{
		this->shape.setSize(sf::Vector2f(256, 64));

		this->text.setString("Button");
		this->text.setCharacterSize(48);
		this->text.setFont(font);
		this->text.setPosition(sf::Vector2f(128 - (this->text.getLocalBounds().width / 2), 32 - (this->text.getLocalBounds().height / 2) - this->text.getLocalBounds().top));
		this->text.setColor(sf::Color(0, 0, 0, 255));
	}
	Button::Button(sf::String text, sf::Vector2f postion, sf::Vector2f size)
	{
		Base();

		this->shape.setPosition(postion);
		this->shape.setSize(size);

		this->text.setString(text);
		this->text.setCharacterSize(size.y - 16);
		this->text.setFont(font);
		this->text.setPosition(sf::Vector2f(postion.x + (size.x / 2) - (this->text.getLocalBounds().width / 2), postion.y + (size.y / 2) - (this->text.getLocalBounds().height / 2) - this->text.getLocalBounds().top));
		this->text.setColor(sf::Color(0, 0, 0, 255));

		state = GUI::State::Idle;
	}

	sf::RectangleShape Button::getShape()
	{
		return shape;
	}

	sf::Text Button::getDrawText()
	{
		return text;
	}
}