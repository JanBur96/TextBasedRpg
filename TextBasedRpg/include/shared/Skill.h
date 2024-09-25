#pragma once
#include <string>

class Skill {
private:
    std::string name;
    int level;
    int damage;
    int manaCost;

public:
    Skill(const std::string& name, int level, int damage, int manaCost) :
        name(name),
        level(level),
        damage(damage),
        manaCost(manaCost)
    {}

    std::string getName() const { return name; }
    int getLevel() const { return level; }
    int getDamage() const { return damage; }
    int getManaCost() const { return manaCost; }
};