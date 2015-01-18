#include "Pickup.h"
#include <iostream>

namespace Pickups
{
	Pickup::Pickup()
	{
		sprite.setScale(0.75f, 0.75f);
		sprite.setOrigin(32.f, 32.f);
	}

	bool Pickup::drop(float dt)
	{
		position.y += 600.f * dt;
		sprite.setPosition(position);
		sprite.rotate(360.f * dt);
		if (position.y > 1080.f)
			return true;
		return false;
	}

	void Pickup::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
	}

	void Pickup::setTexture(sf::Texture* texture)
	{
		sprite.setTexture(*texture);
	}

	sf::Sprite* Pickup::getSprite()
	{
		return &sprite;
	}

	void Pickup::setPos(sf::Vector2f position)
	{
		this->position = position;
		sprite.setPosition(position);
	}
	sf::Vector2f Pickup::getPos()
	{
		return position;
	}

	bool Pickup::isColliding(Player* player)
	{
		if (((player->getPos().x + 16) > position.x - 32) && ((player->getPos().x - 16) < (position.x + 32)) && ((player->getPos().y + 48) > position.y - 32) && ((player->getPos().y - 48) < (position.y + 32)))
		{
			onCollect(player);
			return true;
		}
		return false;
	}
}