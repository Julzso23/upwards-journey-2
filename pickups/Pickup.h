#ifndef PICKUPS_PICKUP_H
#define PICKUPS_PICKUP_H

#include <SFML\Graphics.hpp>
#include "..\Player.h"

namespace Pickups
{
	class Pickup
	{
	private:
		sf::Vector2f position;
		sf::Sprite sprite;
	public:
		Pickup();

		bool drop(float dt);
		void draw(sf::RenderWindow* window);

		void setTexture(sf::Texture* texture);

		sf::Sprite* getSprite();

		void setPos(sf::Vector2f position);
		sf::Vector2f getPos();

		void isColliding(Player* player);

		virtual void onCollect(Player* player) = 0;
	};
}

#endif