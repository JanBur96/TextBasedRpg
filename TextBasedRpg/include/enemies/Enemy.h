#pragma once
#include <string>
#include <vector>

class Enemy {
private:
    std::string name;
    int health;
    int mana;
    int attack;
    int defense;
    int experience;
    int gold;
    std::vector<std::string> drops;

public:
    Enemy(std::string name, int health, int mana, int attack, int defense, int experience, int gold, std::vector<std::string> drops);
    virtual ~Enemy() = default;

    virtual void performAttack();
    void takeDamage(int damage);

    std::string getName() const;
    int getHealth() const;
    int getMana() const;
    int getAttack() const;
    int getDefense() const;
    int getExperience() const;
    int getGold() const;
    std::vector<std::string> getDrops() const;
};