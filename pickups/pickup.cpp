#include "Pickup.h"

namespace Pickups
{
	Pickup::Pickup()
	{
		sprite.setTexture(texture);
	}
	Pickup::Pickup(sf::Vector2f position)
	{
		this->position = position;
		sprite.setTexture(texture);
	}

	bool Pickup::drop(float dt)
	{
		position.y += 800.f * dt;
		sprite.setPosition(position);
		if (position.y > 1080.f)
			return true;
		return false;
	}

	void Pickup::draw(sf::RenderWindow* window)
	{
		window->draw(sprite);
	}

	void Pickup::setTexture(sf::String fileName)
	{
		texture.loadFromFile("images/pickups/" + fileName + ".png");
	}
}