#pragma once
#include "inventory/Equippable.h"
#include <memory>

class Equip {
private:
	Equippable* m_armor = nullptr;
	Equippable* m_weapon = nullptr;
	Equippable* m_accessory = nullptr;

public:
	Equip() : m_armor(nullptr), m_weapon(nullptr), m_accessory(nullptr) {}

	void equipWeapon(Equippable* weapon) { m_weapon = weapon; }
	void equipArmor(Equippable* armor) { m_armor = armor; }
	void equipAccessory(Equippable* accessory) { m_accessory = accessory; }

	void unequipArmor() { m_armor = nullptr; }
	void unequipWeapon() { m_weapon = nullptr; }
	void unequipAccessory() { m_accessory = nullptr; }

	Equippable* getArmor() const { return m_armor; }
	Equippable* getWeapon() const { return m_weapon; }
	Equippable* getAccessory() const { return m_accessory; }
};