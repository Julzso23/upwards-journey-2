#include "Dropdown.h"

namespace GUI
{
	Dropdown::Dropdown()
	{
		create(std::vector<Button>());
	}

	Dropdown::Dropdown(std::vector<Button> elements)
	{
		create(elements);
	}

	void Dropdown::create(std::vector<Button> elements)
	{
		this->elements = elements;
	}
}