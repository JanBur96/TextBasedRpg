#include "gameMechanics/actions/trainingAction.h"
#include <iostream>
#include "common/Utility.h"
#include "common/DataIO.h"

int calculateTrainingCost(int currentAttributeHeight, int basePrice, double scalingFactor) {
    return static_cast<int>(basePrice * std::pow(scalingFactor, currentAttributeHeight - 1));
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

    int trainStrengthChoice{ getNumericInput() };

    switch (trainStrengthChoice)
    {
    case 1:
    {
        player.increaseStrength(1);
        player.payGold(5);
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

    int trainingChoice{ getNumericInput() };

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