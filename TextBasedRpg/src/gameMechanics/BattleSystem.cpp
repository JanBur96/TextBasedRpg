#include <iostream>
#include "gameMechanics/BattleSystem.h"
#include "player/Player.h"
#include "enemies/Enemy.h"
#include "common/DataIO.h"
#include "gameMechanics/actions/combatInventoryAction.h"
#include "quest/Journal.h"
#include "quest/HuntingQuest.h"
#include "inventory/itemMapper.h"
#include "inventory/InventoryItem.h"
#include <memory>

void BattleSystem::handleQuestProgress(Player& player, Enemy& enemy)
{
    auto& journal = player.getJournal();
    auto& openQuests = journal.getOpenQuests();

    for (int i = 0; i < openQuests.size(); ++i)
    {
        auto* huntingQuest = dynamic_cast<HuntingQuest*>(openQuests[i].get());

        if (!huntingQuest || huntingQuest->getMonsterToKill() != enemy.getName())
            continue;

        huntingQuest->incrementMonsterKilled();

        if (huntingQuest->getMonsterKilled() == huntingQuest->getMonsterToKillCount())
        {
            journal.completeQuest(huntingQuest);
            --i;
        }
    }
}

bool BattleSystem::handleFleeAttempt()
{
	//TODO: Implement flee logic, it's always true for now
	std::cout << "You attempt to flee...\n";
	return true;
}

bool BattleSystem::handlePlayerTurn(Player &player, Enemy &enemy)
{
    std::cout << "It's your turn! What do you want to do: " << '\n';
    std::cout << "1. Attack (Melee)" << '\n';
    std::cout << "2. Attack (Skill)" << '\n';
    std::cout << "3. Defend" << '\n';
    std::cout << "4. Use Item" << '\n';
    std::cout << "5. Try To Flee" << '\n';

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
            std::cout << "You successfully fled!" << '\n';
            return false;
        }
        break;
    default:
        std::cout << "Invalid choice. Please try again." << '\n';
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
    handleQuestProgress(player, enemy);

    std::vector<ItemType> droppedItems = enemy.dropItems();
    std::vector<std::unique_ptr<InventoryItem>> items = itemMapper(droppedItems);

    if (!items.empty())
    {
        std::cout << "The enemy dropped: " << '\n';
        for (const auto& item : droppedItems)
		{
            std::cout << itemTypeToString(item) << "\n";
		}
    }
    for (auto& item : items) {
        player.getInventory().addItem(std::move(item));

    }

    player.gainGold(enemy.getGold());
    player.gainExperience(enemy.getExperience());
    std::cout << "You won!" << '\n';

    if (player.canLevelUp())
    {
        std::cout << "Level up!" << '\n';
        std::cout << "You are level " << player.getLevel() << " now." << '\n';
        player.levelUp();
    }
    std::cout << "Press 1 to continue." << '\n';

    int temp{};
    std::cin >> temp;
    return;
}

void BattleSystem::handleDefeat(Player& player)
{
    //todo implement
    std::cout << "Defeated!" << '\n';
}

void BattleSystem::displayCombatStatus(Player& player, Enemy& enemy)
{
    std::cout << "Player HP: " << player.getHealth() << "/" << player.getMaxHealth() << '\n';
    std::cout << "Player MP: " << player.getMana() << "/" << player.getMaxMana() << '\n';
    std::cout << "Enemy HP: " << enemy.getHealth() << "/" << "???" << '\n';
}
