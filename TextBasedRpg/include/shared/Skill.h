#pragma once
#include <string>

class Skill {
private:
    std::string m_name;
    int m_skillLevel;
    int m_skillUnlockLevel;
    int m_skillUnlockCost;
    int m_damage;
    int m_manaCost;

public:
    Skill(const std::string& name, int level, int skillUnlockLevel, int skillUnlockCost, int damage, int manaCost) :
        m_name(name),
        m_skillLevel(level),
        m_skillUnlockLevel(skillUnlockLevel),
        m_skillUnlockCost(skillUnlockCost),
        m_damage(damage),
        m_manaCost(manaCost)
    {}

    const std::string& getName() const { return m_name; }
    int getSkillLevel() const { return m_skillLevel; }
    int getSkillUnlockLevel() const { return m_skillUnlockLevel; }
    int getSkillUnlockCost() const { return m_skillUnlockCost; }
    int getDamage() const { return m_damage; }
    int getManaCost() const { return m_manaCost; }
};