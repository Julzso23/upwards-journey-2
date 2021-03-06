#ifndef PICKUPS_HEALTH_H
#define PICKUPS_HEALTH_H

#include "Pickup.h"

namespace Pickups
{
	class Health : public Pickups::Pickup
	{
	private:
		int worth;
	public:
		Health(sf::Vector2f position, int worth, sf::Texture* texture);
		void create(sf::Vector2f position, int worth, sf::Texture* texure);
		void onCollect(Player* player);
	};
}

#endif