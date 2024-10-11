#pragma once
#include "enemies/Enemy.h"

class IceHawk : public Enemy {
public:
    IceHawk();
    void performAttack() override;
};

class Slime : public Enemy {
public:
    Slime();
    void performAttack() override;
};

class RockGolem : public Enemy {
public:
    RockGolem();
    void performAttack() override;
};