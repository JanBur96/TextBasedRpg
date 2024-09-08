#pragma once
#include "Player.h"

//ViewCharacter
//ViewInventory
//Rest
//Training
//Adventure
//Exit

int calculateTrainingCost(int currentAttributeHeight, int basePrice, double scalingFactor);

void viewCharacterAction(Player& player);

void viewInventoryAction(Player& player);

void restAction(Player& player);

void trainingAction(Player& player);

void adventureAction(Player& player);

void handleVictory(Player& player, Enemy& enemy);