#ifndef PICKUPS_PICKUPDROPPER_H
#define PICKUPS_PICKUPDROPPER_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Health.h"

template <class T>
class PickupDropper
{
private:
	sf::Clock timer;
	float dropRate;
	sf::Texture texture;
	std::vector<T> pickups;
public:
	PickupDropper();
	void create(float dropRate, sf::String textureName);
	void update(float dt, Player* player);
	void draw(sf::RenderWindow* window);
	std::vector<T>* getPickups();
};

#endif