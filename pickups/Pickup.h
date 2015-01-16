#ifndef PICKUPS_PICKUP_H
#define PICKUPS_PICKUP_H

#include <SFML\Graphics.hpp>
#include "..\Player.h"

namespace Pickups
{
	class Pickup : public sf::Drawable
	{
	private:
		sf::Vector2f position;
		sf::Sprite sprite;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		Pickup();

		bool drop(float dt);

		void setTexture(sf::Texture* texture);

		sf::Sprite* getSprite();

		void setPos(sf::Vector2f position);
		sf::Vector2f getPos();

		bool isColliding(Player* player);

		virtual void onCollect(Player* player) = 0;
	};
}

#endif