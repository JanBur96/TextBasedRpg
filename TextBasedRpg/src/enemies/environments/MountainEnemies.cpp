#include "enemies/environments/MountainEnemies.h"
#include <iostream>

IceHawk::IceHawk() : Enemy("Ice Hawk", 450, 100, 60, 45, 180, 90, { "Ice Feather", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "An ice hawk screeches from above!" << "\n";
}

void IceHawk::performAttack() {
    std::cout << "Ice Hawk dive-bombs with razor-sharp talons!" << "\n";
}

Slime::Slime() : Enemy("Slime", 500, 120, 65, 50, 200, 100, { "Slime Essence", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "A gelatinous slime oozes towards you!" << "\n";
}

void Slime::performAttack() {
    std::cout << "Slime engulfs you in its acidic body!" << "\n";
}

RockGolem::RockGolem() : Enemy("Rock Golem", 600, 150, 70, 55, 250, 125, { "Golem Core", "Large Health Potion", "Large Mana Potion", "Rare Mineral" }) {
    std::cout << "A massive rock golem awakens!" << "\n";
}

void RockGolem::performAttack() {
    std::cout << "Rock Golem smashes with its enormous fists!" << "\n";
}