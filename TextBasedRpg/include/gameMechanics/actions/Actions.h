#pragma once
#include "player/Player.h"
#include "adventureAction.h"
#include "trainingAction.h"
#include "restAction.h"
#include "viewCharacterAction.h"
#include "viewInventoryAction.h"

int calculateTrainingCost(int currentAttributeHeight, int basePrice, double scalingFactor);
