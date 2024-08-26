#pragma once
#include "Player.h"
#include "Skill.h"

class Warrior : public Player {
public:
    Warrior(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense, const std::string& location)
        : Player(name, "Warrior", 1, maxHealth, strength, maxMana, maxEnergy, money, defense, location)
    {
        initializeSkills();
    }

private:
    void initializeSkills()
    {
        addSkill(Skill("Heavy Hit", 1, 7, 10));
    }
};