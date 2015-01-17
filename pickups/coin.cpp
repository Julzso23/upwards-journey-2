#include "Coin.h"

namespace Pickups
{
	Coin::Coin(sf::Vector2f position, int worth, sf::Texture* texture)
	{
		create(position, worth, texture);
	}
	void Coin::create(sf::Vector2f position, int worth, sf::Texture* texture)
	{
		setTexture(texture);
		setPos(position);
		this->worth = worth;
		getSprite()->setTextureRect(sf::IntRect(0, 0, 64, 64));
	}

	void Coin::onCollect(Player* player)
	{
		player->addScore(worth);
	}
}