#pragma once
#include <memory>
#include <stdexcept>

#include "enemies/EnemyType.h"
#include "enemies/Enemy.h"
#include "enemies/Enemies.h"
#include "world/AdventureDirection.h"
#include "common/Utility.h"
#include "common/DataIO.h"

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> createEnemy(EnemyType type)
    {
        switch (type)
        {
        case EnemyType::Goblin:
            return std::make_unique<Goblin>();
        case EnemyType::Wolf:
            return std::make_unique<Wolf>();
        case EnemyType::Bear:
            return std::make_unique<Bear>();
        case EnemyType::Orc:
            return std::make_unique<Orc>();
        case EnemyType::Zombie:
            return std::make_unique<Zombie>();
        case EnemyType::Skeleton:
            return std::make_unique<Skeleton>();
        default:
            throw std::invalid_argument("Unknown enemy type");
        }
    }

    static std::unique_ptr<Enemy> generateRandomEnemy(AdventureDirection adventureLocation)
    {
        std::vector<EnemyType> enemyPool;
        handleClearScreen();
        int start, end;

        switch (adventureLocation)
        {
            case AdventureDirection::Forest:
            {
                start = static_cast<int>(EnemyType::ForestStart);
                end = static_cast<int>(EnemyType::ForestEnd);

                for (int i = start + 1; i < end; i++)
                {
                    enemyPool.push_back(static_cast<EnemyType>(i));
                }

                EnemyType randomType = enemyPool[generateRandomNumberInRange(0, enemyPool.size() - 1)];
			    return EnemyFactory::createEnemy(randomType);
            }
            case AdventureDirection::Cave:
            {
                enemyPool = { EnemyType::Orc, EnemyType::Zombie, EnemyType::Skeleton };
                EnemyType randomType = enemyPool[generateRandomNumberInRange(0, enemyPool.size() - 1)];
                return EnemyFactory::createEnemy(randomType);
            }
            default:
				throw std::invalid_argument("Unknown adventure location");  
            // TODO: Implement other Locations
        }
    }
};