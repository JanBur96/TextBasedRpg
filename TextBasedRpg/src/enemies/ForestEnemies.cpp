#include <iostream>
#include "enemies/ForestEnemies.h"

Goblin::Goblin() : Enemy("Goblin", 70, 0, 12, 6, 10, 5, { "Small Health Potion" }) {
    std::cout << "A goblin has appeared!" << std::endl;
}

void Goblin::performAttack() {
    std::cout << "Goblin attacks with its club!" << std::endl;
}

Wolf::Wolf() : Enemy("Wolf", 100, 0, 18, 8, 20, 8, { "Wolf Fur", "Small Health Potion" }) {
    std::cout << "A wolf howls in the distance!" << std::endl;
}
void Wolf::performAttack() {
    std::cout << "Wolf lunges with its fangs!" << std::endl;
}

Bear::Bear() : Enemy("Bear", 180, 0, 25, 15, 35, 15, { "Bear Claw", "Medium Health Potion" }) {
    std::cout << "A bear roars fiercely!" << std::endl;
}
void Bear::performAttack() {
    std::cout << "Bear swipes with its massive paw!" << std::endl;
}