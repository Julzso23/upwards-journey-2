#ifndef PICKUPS_PICKUPDROPPER_H
#define PICKUPS_PICKUPDROPPER_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Health.h"

template <class T>
class PickupDropper : public sf::Drawable
{
private:
	sf::Clock timer;
	float dropRate;
	sf::Texture texture;
	std::vector<T> pickups;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	PickupDropper();
	void create(float dropRate, sf::String textureName);
	void update(float dt, Player* player);
	std::vector<T>* getPickups();
};

#endif