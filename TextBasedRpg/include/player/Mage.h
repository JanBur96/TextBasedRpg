#pragma once
#include "player/Player.h"
#include "shared/Skill.h"
#include "inventory/Consumables.h"
#include <memory>
#include "inventory/Inventory.h"
#include "inventory/InventoryItem.h"
#include "HuntingQuest.h"

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

		std::cout << "You have leveled up! You are now level " << m_level << "!" << std::endl;
	}

private:
	void initializeMage()
	{
		initializeSkills();
		initializeInventory();
	}

	void initializeInventory()
	{
		m_inventory.addItem(std::make_unique<HealthPotion>("Small Potion", 5, 2, 30));
		m_journal.addQuest(std::make_unique<HuntingQuest>("Kill the Wolves!", "You have to kill Wolves", 50, 50, std::vector<std::string>{}, "Wolf", 5));
	}

    void initializeSkills()
    {
        addSkill(Skill("Fireball", 1, 18, 10));
    }
};