#include "Pickup.h"
#include <iostream>

namespace Pickups
{
	Pickup::Pickup()
	{
		setScale(0.75f, 0.75f);
		setOrigin(32.f, 32.f);
	}

	bool Pickup::drop(float dt)
	{
		move(0.f, 600.f * dt);
		rotate(360.f * dt);
		if (getPosition().y > 1080.f)
			return true;
		return false;
	}

	bool Pickup::isColliding(Player* player)
	{
		sf::Vector2f position = getPosition();
		if (((player->getPosition().x + 16) > position.x - 32) && ((player->getPosition().x - 16) < (position.x + 32)) && ((player->getPosition().y + 48) > position.y - 32) && ((player->getPosition().y - 48) < (position.y + 32)))
		{
			onCollect(player);
			return true;
		}
		return false;
	}
}