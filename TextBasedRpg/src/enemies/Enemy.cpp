#include "enemies/Enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int health, int mana, int attack, int defense, int experience, int gold, std::vector<std::string> drops)
    : name(name), health(health), mana(mana), attack(attack), defense(defense), experience(experience), gold(gold), drops(drops) {}

void Enemy::performAttack() {
    std::cout << "Enemy attacks!" << '\n';
}

void Enemy::takeDamage(int damage) {
    health -= (damage);
}

std::vector<std::string> Enemy::dropItems() {
    std::vector<std::string> droppedItems;
    for (const auto& item : drops) {
        if (rand() % 2 == 0) {
            droppedItems.push_back(item);
        }
    }
    return droppedItems;
}

std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getMana() const { return mana; }
int Enemy::getAttack() const { return attack; }
int Enemy::getDefense() const { return defense; }
int Enemy::getExperience() const { return experience; }
int Enemy::getGold() const { return gold; }
std::vector<std::string> Enemy::getDrops() const { return drops; }