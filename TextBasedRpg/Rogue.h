#pragma once
#include "Player.h"
#include "Skill.h"

class Rogue : public Player {
public:
    Rogue(const std::string& name, int maxHealth, int strength, int maxMana, int maxEnergy, int money, int defense, const std::string& location)
        : Player(name, "Rogue", 1, maxHealth, strength, maxMana, maxEnergy, money, defense, location)
    {
        initializeSkills();
    }

private:
    void initializeSkills()
    {
        addSkill(Skill("DaggerThrow", 1, 7, 7));
    }
};