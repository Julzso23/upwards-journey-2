#include "Button.h"

namespace GUI
{
	Button::Button()
	{
		create("Button", sf::Vector2f(0.f, 0.f), sf::Vector2f(256.f, 64.f));
	}
	Button::Button(sf::String text, std::function<void()> func)
	{
		create(text, sf::Vector2f(0.f, 0.f), sf::Vector2f(256.f, 64.f));
		setClickFunc(func);
	}
	Button::Button(sf::String text, sf::Vector2f position, sf::Vector2f size)
	{
		create(text, position, size);
	}

	void Button::create(sf::String text, sf::Vector2f position, sf::Vector2f size)
	{
		Base();

		this->shape.setPosition(position);
		this->shape.setSize(size);

		this->text.setString(text);
		this->text.setCharacterSize(size.y - 16);
		this->text.setFont(font);
		this->text.setPosition(sf::Vector2f(position.x + (size.x / 2) - (this->text.getLocalBounds().width / 2), position.y + (size.y / 2) - (this->text.getLocalBounds().height / 2) - this->text.getLocalBounds().top));
		this->text.setColor(sf::Color(0, 0, 0, 255));

		state = GUI::State::Idle;
	}

	void Button::update(float dt)
	{
		sf::Vector2i mouse = sf::Mouse::getPosition();
		sf::Vector2f pos = shape.getPosition();
		sf::Vector2f size = shape.getSize();
		if ((mouse.x > pos.x) && (mouse.x < pos.x + size.x) && (mouse.y > pos.y) && (mouse.y < pos.y + size.y))
			state = GUI::State::Hover;
		else
			state = GUI::State::Idle;
	}

	void Button::draw(sf::RenderWindow* window)
	{
		window->draw(shape);
		//window->draw(text);
	}

	void Button::mousePressed(sf::Mouse::Button button)
	{
		if (state == GUI::State::Hover)
			state = GUI::State::Click;
	}
	void Button::mouseReleased(sf::Mouse::Button button)
	{
		if (state == GUI::State::Click)
			onClick();
	}

	void Button::setClickFunc(std::function<void()> func)
	{
		onClick = func;
	}

	void Button::setPos(sf::Vector2f position)
	{
		sf::Vector2f size = shape.getSize();
		this->shape.setPosition(position);
		this->text.setPosition(sf::Vector2f(position.x + (size.x / 2) - (this->text.getLocalBounds().width / 2), position.y + (size.y / 2) - (this->text.getLocalBounds().height / 2) - this->text.getLocalBounds().top));
	}
	sf::Vector2f Button::getPos()
	{
		return shape.getPosition();
	}
}