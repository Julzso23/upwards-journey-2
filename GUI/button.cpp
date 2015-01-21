#include "Button.h"

namespace GUI
{
	Button::Button()
	{
		create("Button", sf::Vector2f(0.f, 0.f), sf::Vector2f(256.f, 64.f));
	}
	Button::Button(sf::String text, std::function<void()> func, sf::Font* font)
	{
		create(text, sf::Vector2f(0.f, 0.f), sf::Vector2f(1024.f, 64.f));
		this->text.setFont(*font);
		setClickFunc(func);
	}
	Button::Button(sf::String text, sf::Vector2f position, sf::Vector2f size)
	{
		create(text, position, size);
	}

	void Button::create(sf::String text, sf::Vector2f position, sf::Vector2f size)
	{
		setPosition(position);
		this->shape.setSize(size);

		this->text.setString(text);
		this->text.setColor(sf::Color(0, 0, 0, 255));
		setSize(size);

		state = GUI::State::Idle;
	}

	void Button::update(float dt, sf::Vector2i mousePos)
	{
		sf::Vector2i mouse = mousePos;
		sf::Vector2f pos = getPosition();
		sf::Vector2f size = shape.getSize();
		if ((mouse.x > pos.x) && (mouse.x < pos.x + size.x) && (mouse.y > pos.y) && (mouse.y < pos.y + size.y))
		{
			if (state != GUI::State::Click)
			{
				state = GUI::State::Hover;
				shape.setFillColor(sf::Color(225, 225, 225, 150));
			}
		}
		else
		{
			state = GUI::State::Idle;
			shape.setFillColor(sf::Color(255, 255, 255, 150));
		}
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform = getTransform();
		target.draw(shape, states);
		target.draw(text, states);
	}

	void Button::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
	{
		if ((button == sf::Mouse::Button::Left) && (state == GUI::State::Hover))
		{
			state = GUI::State::Click;
			shape.setFillColor(sf::Color(200, 200, 200, 150));
		}
	}
	void Button::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
	{
		if ((button == sf::Mouse::Button::Left) && (state == GUI::State::Click))
		{
			state = GUI::State::Idle;
			shape.setFillColor(sf::Color(255, 255, 255, 150));
			onClick();
		}
	}

	void Button::setClickFunc(std::function<void()> func)
	{
		onClick = func;
	}

	void Button::setSize(sf::Vector2f size)
	{
		this->shape.setSize(size);
		this->text.setCharacterSize(static_cast<int>(floor(size.y)) - 16);
		this->text.setPosition(sf::Vector2f((size.x / 2) - (this->text.getLocalBounds().width / 2), (size.y / 2) - (this->text.getLocalBounds().height / 2) - this->text.getLocalBounds().top));
	}
	sf::Vector2f Button::getSize()
	{
		return shape.getSize();
	}
}