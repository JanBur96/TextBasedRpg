#pragma once
#include "enemies/Enemy.h"

class Orc : public Enemy {
public:
    Orc();
    void performAttack() override;
};

class Zombie : public Enemy {
public:
    Zombie();
    void performAttack() override;
};

class Skeleton : public Enemy {
public:
    Skeleton();
    void performAttack() override;
};