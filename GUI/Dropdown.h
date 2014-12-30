#ifndef GUI_DROPDOWN_H
#define GUI_DROPDOWN_H

#include "Base.h"
#include "Button.h"
#include <vector>

namespace GUI
{
	class Dropdown : public Base
	{
	private:
		Button expandButton;
		sf::RectangleShape background;
		sf::Text curValue;
		std::vector<Button> elements;
	public:
		Dropdown();
		Dropdown(std::vector<Button> elements);
		void create(std::vector<Button> elements);
	};
}

#endif