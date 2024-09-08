#include "enemies/Enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int health, int mana, int attack, int defense, int experience, int gold, std::vector<std::string> drops)
    : name(name), health(health), mana(mana), attack(attack), defense(defense), experience(experience), gold(gold), drops(drops) {}

void Enemy::performAttack() {
    std::cout << "Enemy attacks!" << std::endl;
}

void Enemy::takeDamage(int damage) {
    health -= (damage - defense);
}

std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getMana() const { return mana; }
int Enemy::getAttack() const { return attack; }
int Enemy::getDefense() const { return defense; }
int Enemy::getExperience() const { return experience; }
int Enemy::getGold() const { return gold; }
std::vector<std::string> Enemy::getDrops() const { return drops; }