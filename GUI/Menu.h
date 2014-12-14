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
		bool enabled;
	public:
		Menu();
		Menu(std::vector<Button> buttons);
		void setButtons(std::vector<Button> buttons);
		void show();
		void hide();
		void update(float dt);
		void draw();
	};
}

#endif