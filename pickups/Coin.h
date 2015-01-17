#ifndef PICKUPS_COIN_H
#define PICKUPS_COIN_H

#include "Pickup.h"

namespace Pickups
{
	class Coin : public Pickup
	{
	private:
		int worth;
	public:
		Coin(sf::Vector2f position, int worth, sf::Texture* texture);
		void create(sf::Vector2f position, int worth, sf::Texture* texure);
		void onCollect(Player* player);
	};
}

#endif