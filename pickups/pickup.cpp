#include "Pickup.h"

namespace Pickups
{
	Pickup::Pickup()
	{
		sprite.setTexture(texture);
	}

	bool Pickup::drop(float dt)
	{
		position.y += 800.f * dt;
		sprite.setPosition(position);
		if (position.y > 1080.f)
			return true;
		return false;
	}

	void Pickup::draw(sf::RenderWindow* window)
	{
		window->draw(sprite);
	}

	void Pickup::setTexture(sf::String fileName)
	{
		texture.loadFromFile("images/pickups/" + fileName + ".png");
		sprite.setTexture(texture);
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

	void Pickup::isColliding(Player* player)
	{
		if (((player->getPos().x + 16) > position.x) && ((player->getPos().x - 16) < (position.x + 64)) && ((player->getPos().y + 48) > position.y) && ((player->getPos().y - 48) < (position.y + 64)))
			onCollect(player);
	}
}