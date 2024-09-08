#include "enemies/DesertEnemies.h"
#include <iostream>

DesertBandit::DesertBandit() : Enemy("Desert Bandit", 320, 50, 45, 30, 100, 50, { "Bandit's Dagger", "Large Health Potion", "Medium Mana Potion" }) {
    std::cout << "A desert bandit emerges from the dunes!" << std::endl;
}

void DesertBandit::performAttack() {
    std::cout << "Desert Bandit slashes with a curved blade!" << std::endl;
}

Scorpion::Scorpion() : Enemy("Scorpion", 350, 0, 50, 35, 120, 60, { "Scorpion Venom", "Large Health Potion", "Antidote" }) {
    std::cout << "A giant scorpion scuttles towards you!" << std::endl;
}

void Scorpion::performAttack() {
    std::cout << "Scorpion strikes with its venomous stinger!" << std::endl;
}

SandWorm::SandWorm() : Enemy("Sand Worm", 400, 80, 55, 40, 150, 75, { "Sand Worm Scale", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "The ground trembles as a sand worm surfaces!" << std::endl;
}

void SandWorm::performAttack() {
    std::cout << "Sand Worm attempts to swallow you whole!" << std::endl;
}