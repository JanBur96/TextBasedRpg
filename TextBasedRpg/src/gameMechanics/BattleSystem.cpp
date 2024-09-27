#include <iostream>
#include "gameMechanics/BattleSystem.h"
#include "player/Player.h"
#include "enemies/Enemy.h"
#include "common/DataIO.h"
#include "gameMechanics/actions/combatInventoryAction.h"

bool BattleSystem::handleFleeAttempt()
{
	//TODO: Implement flee logic, it's always true for now
	std::cout << "You attempt to flee...\n";
	return true;
}

bool BattleSystem::handlePlayerTurn(Player &player, Enemy &enemy)
{
    std::cout << "It's your turn! What do you want to do: " << std::endl;
    std::cout << "1. Attack (Melee)" << std::endl;
    std::cout << "2. Attack (Skill)" << std::endl;
    std::cout << "3. Defend" << std::endl;
    std::cout << "4. Use Item" << std::endl;
    std::cout << "5. Try To Flee" << std::endl;

    int playerChoice{};
    std::cin >> playerChoice;

    switch (playerChoice)
    {   
    case 1:
        printDivider(1, 2);
        player.attackMelee(enemy);
        break;
    case 2:
        player.attackSkill(enemy);
        break;
    case 3:
        //player.defend();
        break;
    case 4:
        combatInventoryAction(player);
        break;
    case 5:
        if (handleFleeAttempt())
        {
            std::cout << "You successfully fled!" << std::endl;
            return false;
        }
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }

    return true;
}

void BattleSystem::handleEnemyTurn(Player& player, Enemy& enemy)
{
    enemy.performAttack();
    player.takeDamage(enemy.getAttack());
}

bool BattleSystem::checkLifeStatus(Player& player, Enemy& enemy)
{
    if (enemy.getHealth() > 0)
    {
        return true;
    }
    else if (enemy.getHealth() <= 0)
    {
        handleVictory(player, enemy);
        return false;
    }
}

void BattleSystem::handleVictory(Player &player, Enemy &enemy)
{
    enemy.getDrops();
    player.gainGold(enemy.getGold());
    player.gainExperience(enemy.getExperience());
    std::cout << "You won!" << std::endl;

    if (player.canLevelUp())
    {
        std::cout << "Level up!" << std::endl;
        std::cout << "You are level " << player.getLevel() << " now." << std::endl;
        player.levelUp();
    }
    std::cout << "Press 1 to continue." << std::endl;

    int temp{};
    std::cin >> temp;
    return;
}

void BattleSystem::handleDefeat(Player& player)
{
    //todo implement
    std::cout << "Defeated!" << std::endl;
}

void BattleSystem::displayCombatStatus(Player& player, Enemy& enemy)
{
    std::cout << "Player HP: " << player.getHealth() << "/" << player.getMaxHealth() << std::endl;
    std::cout << "Player MP: " << player.getMana() << "/" << player.getMaxMana() << std::endl;
    std::cout << "Enemy HP: " << enemy.getHealth() << "/" << "???" << std::endl;
}
