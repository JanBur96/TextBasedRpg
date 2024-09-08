#pragma once
#include "enemies/Enemy.h"

class DesertBandit : public Enemy {
public:
    DesertBandit();
    void performAttack() override;
};

class Scorpion : public Enemy {
public:
    Scorpion();
    void performAttack() override;
};

class SandWorm : public Enemy {
public:
    SandWorm();
    void performAttack() override;
};