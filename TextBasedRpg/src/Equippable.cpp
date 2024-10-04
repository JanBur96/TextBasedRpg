#include "inventory/Equippable.h"
#include <iostream>
#include "player/Equip.h"
#include "player/Player.h"

void Equippable::equipItem(Player& player)
{
	player.getEquip().equipWeapon(this);
}

void Equippable::unequipItem()
{
	std::cout << "Unequip item";
}

void Equippable::printItem()
{
	std::cout << "  Slot: " << getSlot() << "\n";
	std::cout << "  Name: " << getName() << "\n";
	std::cout << "  Value: " << getValue() << "\n";
	std::cout << "  Quantity: " << getQuantity() << "\n";
	std::cout << "  Potency: " << getPotency() << "\n";
	std::cout << "  Req. Level: " << getMinLevel() << "\n";
	std::cout << "  Item Level: " << getEnhancementLevel() << "\n";
}