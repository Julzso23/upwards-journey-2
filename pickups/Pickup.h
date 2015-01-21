#ifndef PICKUPS_PICKUP_H
#define PICKUPS_PICKUP_H

#include <SFML\Graphics.hpp>
#include "..\Player.h"

namespace Pickups
{
	class Pickup : public sf::Sprite
	{
	private:
	public:
		Pickup();

		bool drop(float dt);

		bool isColliding(Player* player);

		virtual void onCollect(Player* player) = 0;
	};
}

#endif