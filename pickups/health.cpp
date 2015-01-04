#include "Health.h"

namespace Pickups
{
	Health::Health(sf::Vector2f position, int worth)
	{
		Pickup(position);
		setTexture("health");
		this->worth = worth;
	}

	void Health::onCollect(Player* player)
	{
		player->addLives(worth);
	}
}