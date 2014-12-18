#include "ObsticleDropper.h"

ObsticleDropper::ObsticleDropper()
{
}
ObsticleDropper::ObsticleDropper(float rate, int minSize, int maxSize)
{
	create(rate, minSize, maxSize);
}

void ObsticleDropper::create(float rate, int minSize, int maxSize)
{
	this->dropRate = rate;
	this->minSize = minSize;
	this->maxSize = maxSize;
}

void ObsticleDropper::update(float dt)
{
	if (timer.getElapsedTime().asSeconds() >= 1 / dropRate)
	{
		timer.restart();
		float size = (rand() % (maxSize - minSize)) + ((maxSize + minSize) / 2);
		obsticles.insert(obsticles.end(), Obsticle(sf::Vector2f((rand() % (1920 / ((maxSize + minSize) / 2))) * ((maxSize + minSize) / 2), -size), size, sf::Vector2f(0.f, (((maxSize + minSize) / 2) * 1200) / size)));
	}

	for (int i = 0; i < obsticles.size(); i++)
	{
		if (obsticles[i].drop(dt))
			obsticles.erase(obsticles.begin() + i);
	}
}

void ObsticleDropper::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < obsticles.size(); i++)
		obsticles[i].draw(window);
}

std::vector<Obsticle>* ObsticleDropper::getObsticles()
{
	return &obsticles;
}