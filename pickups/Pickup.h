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
		sf::Texture texture;
		sf::Sprite sprite;
	public:
		Pickup();

		bool drop(float dt);
		void draw(sf::RenderWindow* window);

		void setTexture(sf::String fileName);

		void setPos(sf::Vector2f position);
		sf::Vector2f getPos();

		virtual void onCollect(Player* player) = 0;
	};
}

#endif