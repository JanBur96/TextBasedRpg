#pragma once
#include "CharacterClass.h"
#include <vector>
#include "Skill.h"
#include "Inventory.h"

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
    int m_money;
    int m_energy;
    int m_maxEnergy;
    int m_defense;
    std::string m_location;
    std::vector<Skill> skills;
    Inventory m_inventory;

public:
    Player(const std::string& name, const std::string& characterClass, int level, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense, std::string location, Inventory inventory = Inventory()) :
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
        m_money(money),
        m_defense(defense),
        m_location(location),
        m_inventory(inventory)
    {}

    void setName(const std::string& name)
    {
        this->m_name = name;
    }

    void addSkill(const Skill& skill)
    {
        skills.push_back(skill);
    }

    void addInventoryItem(const InventoryItem& item)
	{
		m_inventory.addItem(item);
	}

    void rest()
    {
        this->m_mana = m_maxMana;
        this->m_energy = m_maxEnergy;
    }

    bool payMoney(int amount)
    {
        if (this->m_money >= amount)
        {
            this->m_money -= amount;
            return true;
        }

        return false;
    }

    void increaseStrength(int increase)
    {
        this->m_strength += increase;
    }

    std::string getName() const { return m_name; }
    std::string getCharacterClass() const { return m_characterClass; }
    int getLevel() const { return m_level; }
    int getHealth() const { return m_health; }
    int getMaxHealth() const { return m_maxHealth; }
    int getStrength() const { return m_strength; }
    int getMana() const { return m_mana; }
    int getMaxMana() const { return m_maxMana; }
    int getMoney() const { return m_money; }
    int getEnergy() const { return m_energy; }
    int getMaxEnergy() const { return m_maxEnergy; }
    int getDefense() const { return m_defense; }
    std::string getLocation() const { return m_location; }
    const std::vector<Skill>& getSkills() const { return skills; }
    Inventory& getInventory() { return m_inventory; }
};