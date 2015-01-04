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
		Pickup(sf::Vector2f position);

		bool drop(float dt);
		void draw(sf::RenderWindow* window);

		void setTexture(sf::String fileName);

		virtual void onCollect(Player* player);
	};
}

#endif