#ifndef PICKUPS_HEALTH_H
#define PICKUPS_HEALTH_H

#include "Pickup.h"

namespace Pickups
{
	class Health : public Pickup
	{
	private:
		int worth;
	public:
		Health(sf::Vector2f position, int worth);
		void onCollect(Player* player);
	};
}

#endif