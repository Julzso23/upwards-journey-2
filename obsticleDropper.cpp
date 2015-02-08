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
		float size = (float)((rand() % (maxSize - minSize)) + ((maxSize + minSize) / 2));
		obsticles.insert(obsticles.end(), Obsticle(sf::Vector2f((rand() % (1920 / ((maxSize + minSize) / 2))) * ((maxSize + minSize) / 2.f), -size), size, sf::Vector2f(0.f, (((maxSize + minSize) / 2.f) * 1200.f) / size)));
	}

	for (std::size_t i = 0; i < obsticles.size(); i++)
	{
		if (obsticles[i].drop(dt))
			obsticles.erase(obsticles.begin() + i);
	}
}

void ObsticleDropper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (std::size_t i = 0; i < obsticles.size(); i++)
		target.draw(obsticles[i]);
}

std::vector<Obsticle>* ObsticleDropper::getObsticles()
{
	return &obsticles;
}