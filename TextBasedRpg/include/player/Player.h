#pragma once
#include <vector>

#include "player/CharacterClass.h"
#include "shared/Skill.h"
#include "enemies/Enemy.h"
#include "inventory/Inventory.h"
#include <iostream>
#include <memory>
#include "Journal.h"

class Player {
protected:
    std::string m_name;
    std::string m_characterClass;
    int m_level;
    int m_health;
    int m_maxHealth;
    int m_strength;
    int m_mana;
    int m_maxMana;
    int m_gold;
    int m_energy;
    int m_maxEnergy;
    int m_defense;
    int m_experience;
    std::vector<Skill> skills;
    Inventory m_inventory;
    Journal m_journal;

public:
    Player(const std::string& name, const std::string& characterClass, int level, int maxHealth, int strength, int maxMana, int maxEnergy, int gold, int defense, int experience, Inventory inventory = Inventory(), Journal journal = Journal()) :
        m_name(name),
        m_characterClass(characterClass),
        m_level(level),
        m_maxHealth(maxHealth),
        m_health(maxHealth),
        m_strength(strength),
        m_maxMana(maxMana),
        m_mana(maxMana),
        m_maxEnergy(maxEnergy),
        m_energy(maxEnergy),
        m_gold(gold),
        m_defense(defense),
        m_experience(experience),
        m_inventory(std::move(inventory)),
        m_journal(std::move(journal))
    {}

    virtual ~Player() {}

    void restoreHealth(int amount)
	{
		m_health = std::min(m_maxHealth, m_health + amount);
	}

    void restoreMana(int amount)
    {
        m_mana = std::min(m_maxMana, m_mana + amount);
	}

    void setName(const std::string& name)
    {
        m_name = name;
    }

    void addSkill(const Skill& skill)
    {
        skills.push_back(skill);
    }

    int experienceForNextLevel()
	{
		return 100 * m_level * m_level;
	}

    bool canLevelUp()
    {
        return m_experience >= experienceForNextLevel();
    }

    void rest()
    {
        m_mana = m_maxMana;
        m_energy = m_maxEnergy;
        m_health = m_maxHealth;
    }

    virtual void levelUp() = 0;

    bool payGold(int amount)
    {
        if (m_gold >= amount)
        {
            m_gold -= amount;
            return true;
        }

        return false;
    }

    void increaseStrength(int increase)
    {
        m_strength += increase;
    }

    void attackMelee(Enemy& enemy)
    {
        // TODO: Formula
        int damage = m_strength - enemy.getDefense();
        damage = std::max(1, damage);
		enemy.takeDamage(damage);

        std::cout << "You've attacked with your Melee attack!" << '\n';
        std::cout << "The enemy has taken " << damage << " damage." << '\n';
    }

    void attackSkill(Enemy& enemy)
    {
        std::cout << "Which skill do you want to use?" << '\n';
        int i{ 0 };
        for (const Skill& skill : skills)
		{
			std::cout << i + 1 << ". " << skill.getName() << '\n';
		}

        int choice;
        std::cin >> choice;

        Skill chosenSkill{ skills[choice - 1] };
        // TODO Formula

        if (m_mana >= chosenSkill.getManaCost())
        {
            enemy.takeDamage(chosenSkill.getDamage());
            m_mana -= chosenSkill.getManaCost();
        }

    }

    void takeDamage(int damage)
    {
        int damageTaken = std::max(1, damage - getDefense());
        m_health = std::max(0, m_health - damageTaken);

        std::cout << "You've taken " << damageTaken << " damage." << '\n';
    }

    void gainExperience(int experience)
	{
		m_experience += experience;
	}

    void gainGold(int gold)
    {
        m_gold += gold;
    }
    
    std::string getName() const { return m_name; }
    std::string getCharacterClass() const { return m_characterClass; }
    int getLevel() const { return m_level; }
    int getHealth() const { return m_health; }
    int getMaxHealth() const { return m_maxHealth; }
    int getStrength() const { return m_strength; }
    int getMana() const { return m_mana; }
    int getMaxMana() const { return m_maxMana; }
    int getGold() const { return m_gold; }
    int getEnergy() const { return m_energy; }
    int getMaxEnergy() const { return m_maxEnergy; }
    int getDefense() const { return m_defense; }
    int getExperience() const { return m_experience; }
    int getExperienceForNextLevel() { return experienceForNextLevel(); }
    const std::vector<Skill>& getSkills() const { return skills; }
    Inventory& getInventory() { return m_inventory; }
    Journal& getJournal() { return m_journal; }
};