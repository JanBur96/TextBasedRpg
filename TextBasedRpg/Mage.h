#pragma once
#include "Player.h"
#include "Skill.h"

class Mage : public Player {
public:
    Mage(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense, const std::string& location)
        : Player(name, "Mage", 1, maxHealth, strength, maxMana, maxEnergy, money, defense, location)
    {
		initializeMage();
    }

    void levelUp()
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
		addInventoryItem(InventoryItem("Health Potion", "Potion", 10));
		addInventoryItem(InventoryItem("Mana Potion", "Potion", 10));
		addInventoryItem(InventoryItem("Staff", "Weapon", 20));
	}

    void initializeSkills()
    {
        addSkill(Skill("Fireball", 1, 7, 5));
    }
};