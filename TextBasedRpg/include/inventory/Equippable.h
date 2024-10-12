#pragma once
#include "InventoryItem.h"
#include <string>
#include "ItemType.h"

class Equippable : public InventoryItem
{
protected:
	int potency;
	int minLevel;
	int enhancementLevel;
	std::string slot;

public:
	Equippable(ItemType type, std::string name, int value, int quantity, int potency, int minLevel, int enhancementLevel, std::string slot)
		: InventoryItem(type, name, value, quantity), potency(potency), minLevel(minLevel), enhancementLevel(enhancementLevel), slot(slot) {}

	void equipItem(Player&);
	void unequipItem(Player&);
	void printItem();

	int getPotency() const { return potency; }
	int getMinLevel() const { return minLevel; }
	int getEnhancementLevel() const { return enhancementLevel; }
	std::string getSlot() const { return slot; }
};