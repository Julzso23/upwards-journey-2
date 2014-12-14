#include "Menu.h"

namespace GUI
{
	Menu::Menu()
	{
	}
	Menu::Menu(std::vector<Button> buttons)
	{
		this->buttons = buttons;
	}

	void Menu::setButtons(std::vector<Button> buttons)
	{
		this->buttons = buttons;
	}

	void Menu::show()
	{
	}

	void Menu::update(float dt)
	{
	}
}