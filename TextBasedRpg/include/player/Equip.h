#pragma once
#include "inventory/Equippable.h"
#include <memory>
#include "common/DataIO.h"
#include <iostream>

class Player;

class Equip {
private:
	Equippable* m_armor = nullptr;
	Equippable* m_weapon = nullptr;
	Equippable* m_accessory = nullptr;

public:
	Equip() : m_armor(nullptr), m_weapon(nullptr), m_accessory(nullptr) {}

	void equipWeapon(Equippable* weapon, Player& player);
	void equipArmor(Equippable* armor, Player& player);
	void equipAccessory(Equippable* accessory, Player& player);

	void unequipWeapon(Equippable* weapon, Player& player);
	void unequipArmor(Equippable* armor, Player& player);
	void unequipAccessory(Equippable* accessory, Player& player);

	Equippable* getArmor() const { return m_armor; }
	Equippable* getWeapon() const { return m_weapon; }
	Equippable* getAccessory() const { return m_accessory; }

	void printEquip() {
		printListing("Weapon");
		if (getWeapon())
		{
			getWeapon()->printItem();
		} 
		else
		{
			std::cout << "  None" << "\n";
		}

		std::cout << "\n";

		printListing("Armor");
		if (getArmor())
		{
			getArmor()->printItem();
		}
		else
		{
			std::cout << "  None" << "\n";
		}

		std::cout << "\n";

		printListing("Accessory");
		if (getAccessory())
		{
			getAccessory()->printItem();
		}
		else
		{
			std::cout << "  None" << "\n";
		}
	};
};