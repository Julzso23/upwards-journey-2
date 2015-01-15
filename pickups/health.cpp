#include "Health.h"

namespace Pickups
{
	Health::Health()
	{
		initialised = false;
	}
	Health::Health(sf::Vector2f position, int worth)
	{
		create(position, worth);
	}
	void Health::create(sf::Vector2f position, int worth)
	{
		setTexture("health");
		setPos(position);
		this->worth = worth;
		getSprite()->setTextureRect(sf::IntRect(0, 0, 64, 64));
		initialised = true;
	}

	void Health::onCollect(Player* player)
	{
		player->addLives(worth);
	}

	bool Health::isInitialised()
	{
		return initialised;
	}
}