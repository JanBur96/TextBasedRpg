#include <iostream>
#include "Actions.h"
#include "DataIo.h"
#include "EnemyFactory.h"
#include "Enemy.h"

int calculateTrainingCost(int currentAttributeHeight, int basePrice, double scalingFactor) {
    return static_cast<int>(basePrice * std::pow(scalingFactor, currentAttributeHeight - 1));
}

void viewCharacterAction(Player& player)
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
    std::cout << "Location: " << player.getLocation() << std::endl;
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

	int viewCharacterChoice{};
	std::cin >> viewCharacterChoice;

	if (viewCharacterChoice == 1)
	{
		return;
	}
	else
	{
		std::cout << "Invalid choice. Please try again." << std::endl;
	}
}

void viewInventoryAction(Player& player)
{
    printDivider(1, 2);
    std::cout << "View Inventory" << std::endl;
    std::cout << "Money: " << player.getMoney() << std::endl;
    std::cout << "Inventory: " << std::endl;
    for (InventoryItem item : player.getInventory().getItems())
    {
        std::cout << "  Name: " << item.getName() << std::endl;
        std::cout << "  Type: " << item.getCategory() << std::endl;
        std::cout << "  Quantity: " << item.getValue() << std::endl;

    }
    printDivider(1, 2);

    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Back to main menu" << std::endl;

    int viewInventoryChoice{};
    std::cin >> viewInventoryChoice;

    if (viewInventoryChoice == 1)
    {
        return;
    }
    else
    {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void restAction(Player& player)
{
    printDivider(1, 2);
    std::cout << "Welcome in Isabels Inn!" << std::endl;
    std::cout << "Staying a night costs 7 Gold." << std::endl;

    printDivider(1, 2);

    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Stay for the night" << std::endl;
    std::cout << "2. Leave the inn" << std::endl;
    std::cout << "Enter your choice (1-2):" << std::endl;

    int restChoice{};
    std::cin >> restChoice;

    if (restChoice == 1) 
    {
        std::cout << "You slept well and are well rested now." << std::endl;
        player.payMoney(7);
    }
    else if(restChoice == 2) {
        return;
    }
    else
    {
        std::cout << "Invalid choice. Please try again." << std::endl;
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
    
    int trainStrengthChoice;
    std::cin >> trainStrengthChoice;

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

    int trainingChoice{};
    std::cin >> trainingChoice;

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

void displayCombatStatus(Player& player, Enemy& enemy)
{

}

bool playerTurn(Player& player, Enemy& enemy)
{

}

bool enemyTurn(Player& player, Enemy& enemy)
{

}

void handleVictory(Player& player, Enemy& enemy)
{

}

void handleDefeat(Player& player)
{

}

void adventureAction(Player& player)
{
    auto enemy{ EnemyFactory::generateRandomEnemy() };

    bool combatOngoing{ true };

    while (combatOngoing)
    {
        displayCombatStatus(player, *enemy);

        combatOngoing = playerTurn(player, *enemy);
        if (!combatOngoing) break;

        combatOngoing = enemyTurn(player, *enemy);
        if (!combatOngoing) break;
    }
}