#include "world/GameWorld.h"
#include <iostream>
#include "common/Utility.h"

AdventureDirection GameWorld::chooseAdventureDirection()
{
	while (true)
	{
		std::cout << "Where do you want to go?" << "\n";
		std::cout << "1. Forest (Delia)" << "\n";
		std::cout << "2. Cave (Way to Zenonia)" << "\n";
		std::cout << "3. Desert (Way to the Mountains)" << "\n";
		std::cout << "4. Back to main menu" << "\n";
		std::cout << "Enter your choice (1-4):";
		std::cout << std::flush;

		int adventureChoice{ getNumericInput() };

		if (adventureChoice == 4)
		{
			return static_cast<AdventureDirection>(0);
		}
		if (adventureChoice > 4)
		{
			std::cout << "Invalid choice. Please try again." << "\n";
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