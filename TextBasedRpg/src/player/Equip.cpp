#include "player/Equip.h"
#include "player/Player.h"

void Equip::equipWeapon(Equippable* weapon, Player& player)
{
    m_weapon = weapon;
    player.setStrength(player.getStrength() + weapon->getPotency());
}

void Equip::equipArmor(Equippable* armor, Player& player)
{
    m_armor = armor;
    player.setDefense(player.getDefense() + armor->getPotency());
}

void Equip::equipAccessory(Equippable* accessory, Player& player)
{
    //TODO: implement multiple types of accessory stat change
    m_accessory = accessory;
    player.setMaxHealth(player.getMaxHealth() + accessory->getPotency());
}

void Equip::unequipWeapon(Equippable* weapon, Player& player)
{
    if (m_weapon == nullptr)
	{
		return;
	}

    m_weapon = nullptr;
    player.setStrength(player.getStrength() - weapon->getPotency());
}

void Equip::unequipArmor(Equippable* armor, Player& player)
{
    if (m_armor == nullptr)
    {
        return;
	}

    m_armor = nullptr;
    player.setDefense(player.getDefense() - armor->getPotency());
}

void Equip::unequipAccessory(Equippable* accessory, Player& player)
{
    if (m_accessory == nullptr)
	{
		return;
    
    }

    m_accessory = nullptr;
    player.setMaxHealth(player.getMaxHealth() - accessory->getPotency());

    if (player.getHealth() > player.getMaxHealth())
	{
		player.setHealth(player.getMaxHealth());
	}
}
