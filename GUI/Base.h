#ifndef GUI_BASE_H
#define GUI_BASE_H

#include <SFML\Graphics.hpp>

namespace GUI
{
	class Base : public sf::Drawable
	{
	private:
	public:
	};

	enum State
	{
		Idle,
		Hover,
		Click
	};
}

#endif