#pragma once

#include <string>

enum class AdventureDirection
{
	Forest = 1,
	Cave,
	Desert,
};

std::string getAdventureDirectionString(AdventureDirection direction);