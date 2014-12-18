#ifndef OBSTICLEDROPPER_H
#define OBSTICLEDROPPER_H

#include "Obsticle.h"
#include <SFML\Graphics.hpp>
#include <vector>

class ObsticleDropper
{
private:
	sf::Clock timer;
	float dropRate;
	int minSize;
	int maxSize;
	std::vector<Obsticle> obsticles;
public:
	ObsticleDropper();
	ObsticleDropper(float rate, int minSize, int maxSize);
	void create(float rate, int minSize, int maxSize);
	void update(float dt);
	void draw(sf::RenderWindow* window);
	std::vector<Obsticle>* getObsticles();
};

#endif