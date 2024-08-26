#pragma once
#include "EnemyType.h"
#include "Enemy.h"
#include <memory>
#include <stdexcept>
#include <random>

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy(EnemyType type)
    {
        switch (type)
        {
        case EnemyType::Goblin:
            return std::make_unique<Goblin>();
        case EnemyType::Orc:
            return std::make_unique<Orc>();
        case EnemyType::Zombie:
            return std::make_unique<Zombie>();
        case EnemyType::Skeleton:
            return std::make_unique<Skeleton>();
        case EnemyType::Wolf:
            return std::make_unique<Wolf>();
        case EnemyType::Bear:
            return std::make_unique<Bear>();
        default:
            throw std::invalid_argument("Unknown enemy type");
        }
    }

    static std::unique_ptr<Enemy> generateRandomEnemy()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 6);

        EnemyType randomType = static_cast<EnemyType>(distr(gen));

        return EnemyFactory::createEnemy(randomType);
    }
};