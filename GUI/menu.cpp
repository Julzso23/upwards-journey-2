#include "Menu.h"

namespace GUI
{
	Menu::Menu()
	{
		enabled = false;
	}
	Menu::Menu(std::vector<Button> buttons)
	{
		enabled = false;
		setButtons(buttons);
	}

	void Menu::setButtons(std::vector<Button> buttons)
	{
		this->position = sf::Vector2f(0.f, 0.f);
		this->buttons = buttons;
		for (int i = 0; i < this->buttons.size(); i++)
			this->buttons[i].setPos(sf::Vector2f(0.f, i * 134.f));
		setPos(sf::Vector2f(0.f, 540.f - getHeight() / 2.f));
	}

	void Menu::show()
	{
		enabled = true;
	}
	void Menu::hide()
	{
		enabled = false;
	}

	void Menu::update(float dt)
	{
		if (enabled)
			for (int i = 0; i < buttons.size(); i++)
				buttons[i].update(dt);
	}

	void Menu::draw(sf::RenderWindow* window)
	{
		if (enabled)
			for (int i = 0; i < buttons.size(); i++)
				buttons[i].draw(&*window);
	}

	void Menu::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
	{
		if (enabled)
			for (int i = 0; i < buttons.size(); i++)
				buttons[i].mousePressed(button, position);
	}
	void Menu::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
	{
		if (enabled)
			for (int i = 0; i < buttons.size(); i++)
				buttons[i].mouseReleased(button, position);
	}

	void Menu::setPos(sf::Vector2f position)
	{
		this->position = position;
		for (int i = 0; i < this->buttons.size(); i++)
			this->buttons[i].setPos(sf::Vector2f(this->position.x, this->position.y + i * 134.f));
	}
	sf::Vector2f Menu::getPos()
	{
		return position;
	}

	int Menu::getHeight()
	{
		return buttons.size() * 128 + (buttons.size() - 1) * 6;
	}
}