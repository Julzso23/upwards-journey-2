#include "PickupDropper.h"

template <class T>
PickupDropper<T>::PickupDropper()
{
}
template <class T>
void PickupDropper<T>::create(float dropRate, sf::String textureName)
{
	this->dropRate = dropRate;
	this->texture.loadFromFile("images/pickups/" + textureName + ".png");
}

template <class T>
void PickupDropper<T>::update(float dt, Player* player)
{
	if (timer.getElapsedTime().asSeconds() >= 1 / dropRate)
	{
		timer.restart();
		pickups.insert(pickups.end(), T(sf::Vector2f((rand() % 192) * 10.f, -48.f), 1, &texture));
	}
	for (std::size_t i = 0; i < pickups.size(); i++)
	{
		if (pickups[i].drop(dt) || pickups[i].isColliding(player))
			pickups.erase(pickups.begin() + i);
	}
}

template <class T>
void PickupDropper<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (std::size_t i = 0; i < pickups.size(); i++)
		target.draw(pickups[i]);
}

template <class T>
std::vector<T>* PickupDropper<T>::getPickups()
{
	return &pickups;
}

template class PickupDropper <Pickups::Health>;
template class PickupDropper <Pickups::Coin>;