#include "gameMechanics/actions/adventureAction.h"
#include <iostream>
#include "gameMechanics/BattleSystem.h"
#include "world/GameWorld.h"
#include "enemies/EnemyFactory.h"
#include "common/Utility.h"
#include "common/DataIO.h"

void adventureAction(Player& player)
{
    BattleSystem battleSystem;
    GameWorld gameWorld;

    handleClearScreen();
    printHeadline("Adventure");

    AdventureDirection location; 
    location = gameWorld.chooseAdventureDirection();

    if (location == AdventureDirection::Return)
    {
        return;
    }

    auto enemy{ EnemyFactory::generateRandomEnemy(location) };

    bool combatOngoing{ true };

    while (combatOngoing)
    {
        printDivider(1, 2);
        battleSystem.displayCombatStatus(player, *enemy);

        printDivider(1, 2);
        combatOngoing = battleSystem.handlePlayerTurn(player, *enemy);
        if (!combatOngoing) break;

        combatOngoing = battleSystem.checkLifeStatus(player, *enemy);
        if (!combatOngoing) break;

        printDivider(1, 2);
        battleSystem.handleEnemyTurn(player, *enemy);
        combatOngoing = battleSystem.checkLifeStatus(player, *enemy);
        if (!combatOngoing) break;
    }
}