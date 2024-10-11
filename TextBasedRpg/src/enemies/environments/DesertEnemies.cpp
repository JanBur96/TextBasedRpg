#include "enemies/environments/DesertEnemies.h"
#include <iostream>

DesertBandit::DesertBandit() : Enemy("Desert Bandit", 320, 50, 45, 30, 100, 50, { "Bandit's Dagger", "Large Health Potion", "Medium Mana Potion" }) {
    std::cout << "A desert bandit emerges from the dunes!" << "\n";
}

void DesertBandit::performAttack() {
    std::cout << "Desert Bandit slashes with a curved blade!" << "\n";
}

Scorpion::Scorpion() : Enemy("Scorpion", 350, 0, 50, 35, 120, 60, { "Scorpion Venom", "Large Health Potion", "Antidote" }) {
    std::cout << "A giant scorpion scuttles towards you!" << "\n";
}

void Scorpion::performAttack() {
    std::cout << "Scorpion strikes with its venomous stinger!" << "\n";
}

SandWorm::SandWorm() : Enemy("Sand Worm", 400, 80, 55, 40, 150, 75, { "Sand Worm Scale", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "The ground trembles as a sand worm surfaces!" << "\n";
}

void SandWorm::performAttack() {
    std::cout << "Sand Worm attempts to swallow you whole!" << "\n";
}