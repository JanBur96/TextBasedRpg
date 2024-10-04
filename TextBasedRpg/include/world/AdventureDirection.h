#pragma once

#include <string>

enum class AdventureDirection
{
	Return,
	Forest,
	Cave,
	Desert,
};

std::string getAdventureDirectionString(AdventureDirection direction);