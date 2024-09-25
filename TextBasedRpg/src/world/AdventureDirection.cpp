#include "world/AdventureDirection.h"
#include <string>

std::string getAdventureDirectionString(AdventureDirection direction)
{
    switch (direction)
    {
    case AdventureDirection::Forest:
        return "Forest";
    case AdventureDirection::Cave:
        return "Cave";
    case AdventureDirection::Desert:
        return "Desert";
    default:
        return "Unknown";
    }
}