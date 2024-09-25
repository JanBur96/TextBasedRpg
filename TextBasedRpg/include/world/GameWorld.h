#pragma once
#include "AdventureDirection.h"

class GameWorld {
private:
	int m_currentLocation;
	AdventureDirection m_currentAdventureDirection;

public:
	AdventureDirection chooseAdventureDirection();
	void setCurrentAdventureDirection(AdventureDirection);
	AdventureDirection getCurrentAdventureDirection();
};