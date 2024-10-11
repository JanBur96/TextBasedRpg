#include "enemies/environments/CaveEnemies.h"
#include <iostream>

Orc::Orc() : Enemy("Orc", 220, 20, 30, 20, 50, 25, { "Orc Tooth", "Medium Health Potion" }) {
    std::cout << "An orc grunts menacingly!" << "\n";
}

void Orc::performAttack() {
    std::cout << "Orc swings its crude axe!" << "\n";
}

Zombie::Zombie() : Enemy("Zombie", 250, 0, 35, 22, 65, 30, { "Zombie Flesh", "Medium Health Potion", "Small Mana Potion" }) {
    std::cout << "A zombie shambles towards you!" << "\n";
}

void Zombie::performAttack() {
    std::cout << "Zombie attempts to bite you!" << "\n";
}

Skeleton::Skeleton() : Enemy("Skeleton", 280, 40, 40, 25, 80, 40, { "Bone Shard", "Large Health Potion", "Medium Mana Potion" }) {
    std::cout << "A skeleton rattles its bones!" << "\n";
}

void Skeleton::performAttack() {
    std::cout << "Skeleton fires a bone arrow!" << "\n";
}