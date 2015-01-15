#ifndef PICKUPS_HEALTH_H
#define PICKUPS_HEALTH_H

#include "Pickup.h"

namespace Pickups
{
	class Health : public Pickups::Pickup
	{
	private:
		int worth;
		bool initialised;
	public:
		Health();
		Health(sf::Vector2f position, int worth);
		void create(sf::Vector2f position, int worth);
		void onCollect(Player* player);
		bool isInitialised();
	};
}

#endif