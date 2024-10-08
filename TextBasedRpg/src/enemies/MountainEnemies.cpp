#include "enemies/MountainEnemies.h"
#include <iostream>

IceHawk::IceHawk() : Enemy("Ice Hawk", 450, 100, 60, 45, 180, 90, { "Ice Feather", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "An ice hawk screeches from above!" << std::endl;
}

void IceHawk::performAttack() {
    std::cout << "Ice Hawk dive-bombs with razor-sharp talons!" << std::endl;
}

Slime::Slime() : Enemy("Slime", 500, 120, 65, 50, 200, 100, { "Slime Essence", "Large Health Potion", "Large Mana Potion" }) {
    std::cout << "A gelatinous slime oozes towards you!" << std::endl;
}

void Slime::performAttack() {
    std::cout << "Slime engulfs you in its acidic body!" << std::endl;
}

RockGolem::RockGolem() : Enemy("Rock Golem", 600, 150, 70, 55, 250, 125, { "Golem Core", "Large Health Potion", "Large Mana Potion", "Rare Mineral" }) {
    std::cout << "A massive rock golem awakens!" << std::endl;
}

void RockGolem::performAttack() {
    std::cout << "Rock Golem smashes with its enormous fists!" << std::endl;
}