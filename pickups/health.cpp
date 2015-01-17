#include "Health.h"

namespace Pickups
{
	Health::Health(sf::Vector2f position, int worth, sf::Texture* texture)
	{
		create(position, worth, texture);
	}
	void Health::create(sf::Vector2f position, int worth, sf::Texture* texture)
	{
		setTexture(texture);
		setPos(position);
		this->worth = worth;
		getSprite()->setTextureRect(sf::IntRect(0, 0, 64, 64));
	}

	void Health::onCollect(Player* player)
	{
		player->addLives(worth);
	}
}