#include "Game.h"
#include "UJ.h"

int main()
{
	UJ upwardsJourney("Upwards Journey 2", sf::VideoMode::getDesktopMode(), true);
	upwardsJourney.run();

	return 0;
}