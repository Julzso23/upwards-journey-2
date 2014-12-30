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
		if (getHeight() > 1080)
		{
			int size = this->buttons.size();
			for (int i = 0; i < size; i++)
				this->buttons[i].setSize(sf::Vector2f(1024.f, (1080.f / size) - 6.f));
		}
		for (int i = 0; i < this->buttons.size(); i++)
			this->buttons[i].setPos(sf::Vector2f(0.f, i * (((buttons.size() > 0) ? buttons[0].getSize().y : 0.f) + 6.f)));
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

	void Menu::update(float dt, sf::Vector2i mousePos)
	{
		if (enabled)
			for (int i = 0; i < buttons.size(); i++)
				buttons[i].update(dt, mousePos);
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
			this->buttons[i].setPos(sf::Vector2f(this->position.x, this->position.y + i * (((buttons.size() > 0) ? buttons[0].getSize().y : 0.f) + 6.f)));
	}
	sf::Vector2f Menu::getPos()
	{
		return position;
	}

	float Menu::getHeight()
	{
		return buttons.size() * ((buttons.size() > 0) ? buttons[0].getSize().y : 0) + (buttons.size() - 1) * 6;
	}
}