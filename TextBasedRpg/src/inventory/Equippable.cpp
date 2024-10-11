#include "inventory/Equippable.h"
#include <iostream>
#include "player/Equip.h"
#include "player/Player.h"

void Equippable::equipItem(Player& player)
{
	if (getSlot() == "Weapon")
	{
		player.getEquip().equipWeapon(this, player);
	}
	else if (getSlot() == "Armor")
	{
		player.getEquip().equipArmor(this, player);
	}
	else if (getSlot() == "Accessory")
	{
		player.getEquip().equipAccessory(this, player);
	}
}

void Equippable::unequipItem(Player& player)
{
	player.getEquip().unequipWeapon(this, player);
}

void Equippable::printItem()
{
	std::cout << "  Name: " << getName() << "\n";
	std::cout << "  Potency: " << getPotency() << "\n";
	std::cout << "  Req. Level: " << getMinLevel() << "\n";
	std::cout << "  Item Level: " << getEnhancementLevel() << "\n";
	std::cout << "  Quantity: " << getQuantity() << "\n";
	std::cout << "  Value: " << getValue() << "\n";
}