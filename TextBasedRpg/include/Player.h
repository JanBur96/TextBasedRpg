#pragma once
#include <vector>

#include "CharacterClass.h"
#include "Skill.h"
#include "Inventory.h"
#include "enemies/Enemy.h"

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
    int m_experience;
    std::string m_location;
    std::vector<Skill> skills;
    Inventory m_inventory;

public:
    Player(const std::string& name, const std::string& characterClass, int level, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense, int experience, std::string location, Inventory inventory = Inventory()) :
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
        m_experience(experience),
        m_location(location),
        m_inventory(inventory)
    {}

    virtual ~Player() {}

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
        this->m_mana = m_maxMana;
        this->m_energy = m_maxEnergy;
        this->m_health = m_maxHealth;
    }

    virtual void levelUp() = 0;

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

    void attackMelee(Enemy& enemy)
    {
        // TODO: Formula
        int damage = this->m_strength - enemy.getDefense();
		enemy.takeDamage(damage);

        std::cout << "You've attacked with your Melee attack!" << std::endl;
        std::cout << "The enemy has taken " << damage << " damage." << std::endl;
    }

    void attackSkill(Enemy& enemy)
    {
        std::cout << "Which skill do you want to use?" << std::endl;
        for (int i = 0; i < skills.size(); i++)
		{
			std::cout << i + 1 << ". " << skills[i].getName() << std::endl;
		}

        int choice;
        std::cin >> choice;

        Skill chosenSkill{ this->skills[choice - 1] };
        // TODO Formula

        if (this->m_mana >= chosenSkill.getManaCost())
        {
            enemy.takeDamage(chosenSkill.getDamage());
            this->m_mana -= chosenSkill.getManaCost();
        }

    }

    void takeDamage(int damage)
    {
        int damageTaken = std::max(1, damage - this->getDefense());
        this->m_health = std::max(0, this->m_health - damageTaken);

        std::cout << "You've taken " << damageTaken << " damage." << std::endl;
    }

    void gainExperience(int experience)
	{
		this->m_experience += experience;
	}

    void gainGold(int gold)
    {
        this->m_money += gold;
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
    int getExperience() const { return m_experience; }
    int getExperienceForNextLevel() { return experienceForNextLevel(); }
    std::string getLocation() const { return m_location; }
    const std::vector<Skill>& getSkills() const { return skills; }
    Inventory& getInventory() { return m_inventory; }
};