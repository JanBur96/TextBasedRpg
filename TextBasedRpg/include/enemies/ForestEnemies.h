#pragma once
#include "enemies/Enemy.h"

class Goblin : public Enemy {
public:
    Goblin();
    void performAttack() override;
};

class Wolf : public Enemy {
public:
    Wolf();
    void performAttack() override;
};

class Bear : public Enemy {
public:
    Bear();
    void performAttack() override;
};