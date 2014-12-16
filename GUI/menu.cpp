#include "Menu.h"

namespace GUI
{
	Menu::Menu()
	{
	}
	Menu::Menu(std::vector<Button> buttons)
	{
		this->buttons = buttons;
		for (int i = 0; i < this->buttons.size(); i++)
			this->buttons[i].setPos(sf::Vector2f(0.f, i * 65.f));
	}

	void Menu::setButtons(std::vector<Button> buttons)
	{
		this->buttons = buttons;
		for (int i = 0; i < this->buttons.size(); i++)
			this->buttons[i].setPos(sf::Vector2f(0.f, i * 65.f));
	}

	void Menu::show()
	{
	}

	void Menu::update(float dt)
	{
	}

	void Menu::draw(sf::RenderWindow* window)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i].draw(&*window);
		}
	}

	void Menu::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
	{
	}
	void Menu::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
	{
	}
}