#include "world/GameWorld.h"
#include <iostream>
#include "common/Utility.h"

AdventureDirection GameWorld::chooseAdventureDirection()
{
	while (true)
	{
		std::cout << "Where do you want to go?" << std::endl;
		std::cout << "1. Forest (Delia)" << std::endl;
		std::cout << "2. Cave (Way to Zenonia)" << std::endl;
		std::cout << "3. Desert (Way to the Mountains)" << std::endl;
		std::cout << "4. Back to main menu" << std::endl;
		std::cout << "Enter your choice (1-4):";
		std::cout << std::flush;

		int adventureChoice{ getNumericInput() };

		if (adventureChoice > 4)
		{
			std::cout << "Invalid choice. Please try again." << std::endl;
			continue;
		}

		setCurrentAdventureDirection(static_cast<AdventureDirection>(adventureChoice));

		return static_cast<AdventureDirection>(adventureChoice);
	}
}

void GameWorld::setCurrentAdventureDirection(AdventureDirection direction)
{
	m_currentAdventureDirection = direction;
}

AdventureDirection GameWorld::getCurrentAdventureDirection()
{
	return m_currentAdventureDirection;
}