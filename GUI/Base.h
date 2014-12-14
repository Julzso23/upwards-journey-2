#ifndef GUI_BASE_H
#define GUI_BASE_H

#include <SFML\Graphics.hpp>

namespace GUI
{
	class Base
	{
	private:
	public:
		Base();
		sf::Font font;
	};

	enum State
	{
		Idle,
		Hover,
		Click
	};
}

#endif