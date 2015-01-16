#ifndef OBSTICLEDROPPER_H
#define OBSTICLEDROPPER_H

#include "Obsticle.h"
#include <SFML\Graphics.hpp>
#include <vector>

class ObsticleDropper : public sf::Drawable
{
private:
	sf::Clock timer;
	float dropRate;
	int minSize;
	int maxSize;
	std::vector<Obsticle> obsticles;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	ObsticleDropper();
	ObsticleDropper(float rate, int minSize, int maxSize);
	void create(float rate, int minSize, int maxSize);
	void update(float dt);
	std::vector<Obsticle>* getObsticles();
};

#endif