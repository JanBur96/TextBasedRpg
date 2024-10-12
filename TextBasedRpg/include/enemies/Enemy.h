#pragma once
#include <string>
#include <vector>
#include "inventory/ItemType.h"

class Enemy {
private:
    std::string name;
    int health;
    int mana;
    int attack;
    int defense;
    int experience;
    int gold;
    std::vector<ItemType> drops;

public:
    Enemy(std::string name, int health, int mana, int attack, int defense, int experience, int gold, std::vector<ItemType> drops);
    virtual ~Enemy() = default;

    virtual void performAttack();
    void takeDamage(int damage);
    std::vector<ItemType> dropItems();

    std::string getName() const;
    int getHealth() const;
    int getMana() const;
    int getAttack() const;
    int getDefense() const;
    int getExperience() const;
    int getGold() const;
    std::vector<ItemType> getDrops() const;
};