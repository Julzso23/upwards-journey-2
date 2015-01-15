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

	void Pickup::draw(sf::RenderWindow* window)
	{
		window->draw(sprite);
	}

	void Pickup::setTexture(sf::String name)
	{
		if (!texture.loadFromFile("images/pickups/" + name + ".png"))
			std::cout << "Error loading image: images/pickups/" + name.toAnsiString() + ".png" << std::endl;
		else
			sprite.setTexture(texture);
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

	void Pickup::isColliding(Player* player)
	{
		if (((player->getPos().x + 16) > position.x) && ((player->getPos().x - 16) < (position.x + 64)) && ((player->getPos().y + 48) > position.y) && ((player->getPos().y - 48) < (position.y + 64)))
			onCollect(player);
	}
}