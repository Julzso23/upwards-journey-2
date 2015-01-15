#include "PickupDropper.h"

template <class T>
PickupDropper<T>::PickupDropper()
{
}
template <class T>
void PickupDropper<T>::create(float dropRate)
{
	this->dropRate = dropRate;
}

template <class T>
void PickupDropper<T>::update(float dt, Player* player)
{
	if (timer.getElapsedTime().asSeconds() >= 1 / dropRate)
	{
		timer.restart();
		pickups.insert(pickups.end(), T());
	}
	for (int i = 0; i < pickups.size(); i++)
	{
		if (!pickups[i].isInitialised())
			pickups[i].create(sf::Vector2f((rand() % 192) * 10.f, -48.f), 1);
		pickups[i].drop(dt);
		pickups[i].isColliding(player);
	}
}

template <class T>
void PickupDropper<T>::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < pickups.size(); i++)
		pickups[i].draw(window);
}

template <class T>
std::vector<T>* PickupDropper<T>::getPickups()
{
	return &pickups;
}

template class PickupDropper <Pickups::Health>;