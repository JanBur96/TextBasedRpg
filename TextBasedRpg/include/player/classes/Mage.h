#pragma once
#include "player/Player.h"
#include "player/Skill.h"
#include "inventory/Consumables.h"
#include <memory>
#include "inventory/Inventory.h"
#include "inventory/InventoryItem.h"
#include "quest/HuntingQuest.h"
#include "enemies/Enemies.h"
#include "inventory/Equippable.h"

class Mage : public Player {
public:
	Mage(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int gold, int defense)
		: Player(name, "Mage", 1, maxHealth, strength, maxMana, maxEnergy, gold, defense, 0)
	{
		initializeMage();
	}

    void levelUp() override
	{
		m_level++;
		m_maxHealth += 5;
		m_health = m_maxHealth;
		m_strength += 2;
		m_maxMana += 10;
		m_mana = m_maxMana;
		m_maxEnergy += 5;
		m_energy = m_maxEnergy;
		m_defense += 1;
		m_experience = 0;

		std::cout << "You have leveled up! You are now level " << m_level << "!" << "\n";
	}

private:
	void initializeMage()
	{
		initializeInventory();
	}

	void initializeInventory()
	{
		m_inventory.addItem(std::make_unique<Equippable>("Wooden Sword", 10, 1, 10, 1, 1, "Weapon"));
		m_inventory.addItem(std::make_unique<Equippable>("Plate Armor", 10, 1, 8, 1, 1, "Armor"));
		m_inventory.addItem(std::make_unique<Equippable>("Bronze Necklace", 10, 1, 5, 1, 1, "Accessory"));
		m_inventory.addItem(std::make_unique<HealthPotion>("Small Potion", 5, 2, 30));
		m_journal.addQuest(std::make_unique<HuntingQuest>("Hunting Quest", "Kill the Wolves!", "You have to kill Wolves", 50, 50, std::vector<std::string>{}, "Wolf", 1));
	}
};