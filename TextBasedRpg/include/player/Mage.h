#pragma once
#include "player/Player.h"
#include "shared/Skill.h"
#include "player/Consumables.h"
#include <memory>
#include "player/Inventory.h"
#include "player/InventoryItem.h"

class Mage : public Player {
public:
	Mage(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense)
		: Player(name, "Mage", 1, maxHealth, strength, maxMana, maxEnergy, money, defense, 0)
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
		//addInventoryItem(InventoryItem("Mana Potion", "Potion", 10));
	}

    void initializeSkills()
    {
        addSkill(Skill("Fireball", 1, 18, 10));
    }
};