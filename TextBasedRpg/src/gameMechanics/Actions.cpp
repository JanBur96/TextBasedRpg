#include <iostream>
#include "gameMechanics/actions/Actions.h"
#include "common/DataIO.h"
#include "enemies/EnemyFactory.h"
#include "enemies/Enemy.h"
#include "common/Utility.h"
#include "gameMechanics/BattleSystem.h"
#include "world/GameWorld.h"
#include <memory>
#include "common/Utility.h"
#include "player/Inventory.h"
#include "player/InventoryItem.h"

int calculateTrainingCost(int currentAttributeHeight, int basePrice, double scalingFactor) {
    return static_cast<int>(basePrice * std::pow(scalingFactor, currentAttributeHeight - 1));
}

void viewCharacterAction(Player& player)
{
    while (true)
    {
	    printDivider(1, 2, true);
        std::cout << "View Character" << std::endl;
        std::cout << "Name: " << player.getName() << std::endl;
        std::cout << "Class: " << player.getCharacterClass() << std::endl;
        std::cout << "Level: " << player.getLevel() << std::endl;
        std::cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << std::endl;
        std::cout << "Mana: " << player.getMana() << "/" << player.getMaxMana() << std::endl;
        std::cout << "Strength: " << player.getStrength() << std::endl;
        std::cout << "Defense: " << player.getDefense() << std::endl;
        std::cout << "Experience: " << player.getExperience() << "/" << player.getExperienceForNextLevel() << std::endl;
        std::cout << "Skills: " << std::endl;
        for (Skill skill : player.getSkills())
        {
        std::cout << "  Name: " << skill.getName() << std::endl;
        std::cout << "  Level: " << skill.getLevel() << std::endl;
        std::cout << "  Damage: " << skill.getDamage() << std::endl;
        std::cout << "  Mana cost: " << skill.getManaCost() << std::endl;
        }
        std::cout << "Energy: " << player.getEnergy() << "/" << player.getMaxEnergy() << std::endl;
	    printDivider(1, 2);

	    std::cout << "What do you want to do?" << std::endl;
	    std::cout << "1. Back to main menu" << std::endl;

	    int viewCharacterChoice{getNumericInput()};

	    if (viewCharacterChoice == 1)
	    {
		    return;
	    }
	    else
	    {
		    std::cout << "Invalid choice. Please try again." << std::endl;
	    }
    }
}

void viewInventoryAction(Player& player)
{
    Inventory& playerInventory{ player.getInventory() };
    const std::vector<std::unique_ptr<InventoryItem>>& inventoryItems{ playerInventory.getItems() };

    if (inventoryItems.empty())
	{
        printDivider(1, 2);
		std::cout << "Your inventory is empty." << std::endl;
		return;
    }
    else
    {
        while (true)
        {
            printDivider(1, 2);
            int itemIndex{ 1 };
            std::cout << "View Inventory" << std::endl;
            std::cout << "Gold: " << player.getMoney() << std::endl;
            std::cout << "Inventory: " << std::endl;
            for (const auto& item : player.getInventory().getItems())
            {
                std::cout << itemIndex << "." << std::endl;
                item->printItem();
                itemIndex++;
            }

            printDivider(1, 2);

            std::cout << "What do you want to do?" << std::endl;
            std::cout << "1. Use item" << std::endl;
            std::cout << "2. Drop item" << std::endl;
            std::cout << "3. Back to main menu" << std::endl;

            int viewInventoryChoice{getNumericInput()};

            switch (viewInventoryChoice)
            {
                case 1:
                    {
                        std::cout << "Which Item do you want to use? Enter the number of the item: ";
                        int itemToUseIndex{ getNumericInput() };

                        InventoryItem* itemToUse = inventoryItems[itemToUseIndex - 1].get();
                        itemToUse->useItem(player, itemToUseIndex);

                        return;
                    }
                case 2:
                    {
                        std::cout << "Which Item do you want to drop? Enter the number of the item: ";
                        int itemToDropIndex{ getNumericInput() };

                        playerInventory.deleteItem(itemToDropIndex - 1);

                        return;
                    }
                case 3:
                    return;
            } 
        }
    }
}

void handleTrainStrength(Player& player)
{
    int traningCost{ calculateTrainingCost(player.getStrength(), 5, 1.2) };

    std::cout << "Training your strength will cost you " << traningCost << " Gold." << std::endl;
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Train your strength" << std::endl;
    std::cout << "2. Go back to the training ground." << std::endl;
    std::cout << "3. Go back to main menu" << std::endl;
    std::cout << "Enter your choice (1-3):" << std::endl;
    
    int trainStrengthChoice{getNumericInput()};

    switch (trainStrengthChoice)
    {
    case 1:
    {
        player.increaseStrength(1);
        player.payMoney(5);
        break;
    }
    case 2:
        //
        break;
    case 3:
        //
        break;
    }
}

void trainingAction(Player& player)
{
    printDivider(1, 2);
    std::cout << "Welcome to the training ground!" << std::endl;
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Train your strength" << std::endl;
    std::cout << "2. Train your defense" << std::endl;
    std::cout << "3. Train your mana" << std::endl;
    std::cout << "4. Train your energy" << std::endl;
    std::cout << "5. Train your health" << std::endl;
    std::cout << "6. Train your skills" << std::endl;
    std::cout << "7. Leave the training ground" << std::endl;
    std::cout << "Enter your choice (1-7):" << std::endl;

    int trainingChoice{getNumericInput()};

    switch (trainingChoice)
    {
    case 1:
        handleTrainStrength(player);
        break;
    case 2:
        //player.trainDefense();
        break;
    case 3:
        //player.trainMana();
        break;
    case 4:
        //player.trainEnergy();
        break;
    case 5:
        //player.trainHealth();
        break;
    case 6:
        //player.trainSkills();
        break;
    case 7:
        return;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }
}

void adventureAction(Player& player)
{
    printDivider(1, 2, true);

    BattleSystem battleSystem;
    GameWorld gameWorld;

    std::cout << "You are currently in the " << getAdventureDirectionString(gameWorld.getCurrentAdventureDirection()) << "." << std::endl;

    AdventureDirection location = gameWorld.chooseAdventureDirection();
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