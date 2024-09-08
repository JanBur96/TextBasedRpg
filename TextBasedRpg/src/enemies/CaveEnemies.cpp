#include "enemies/CaveEnemies.h"
#include <iostream>

Orc::Orc() : Enemy("Orc", 220, 20, 30, 20, 50, 25, { "Orc Tooth", "Medium Health Potion" }) {
    std::cout << "An orc grunts menacingly!" << std::endl;
}

void Orc::performAttack() {
    std::cout << "Orc swings its crude axe!" << std::endl;
}

Zombie::Zombie() : Enemy("Zombie", 250, 0, 35, 22, 65, 30, { "Zombie Flesh", "Medium Health Potion", "Small Mana Potion" }) {
    std::cout << "A zombie shambles towards you!" << std::endl;
}

void Zombie::performAttack() {
    std::cout << "Zombie attempts to bite you!" << std::endl;
}

Skeleton::Skeleton() : Enemy("Skeleton", 280, 40, 40, 25, 80, 40, { "Bone Shard", "Large Health Potion", "Medium Mana Potion" }) {
    std::cout << "A skeleton rattles its bones!" << std::endl;
}

void Skeleton::performAttack() {
    std::cout << "Skeleton fires a bone arrow!" << std::endl;
}