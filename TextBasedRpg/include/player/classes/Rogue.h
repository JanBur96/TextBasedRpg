#pragma once
#include "player/Player.h"
#include "player/Skill.h"

class Rogue : public Player {
public:
    Rogue(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense)
        : Player(name, "Rogue", 1, maxHealth, strength, maxMana, maxEnergy, money, defense, 0)
    {
        initializeSkills();
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
    void initializeSkills()
    {
    }
};