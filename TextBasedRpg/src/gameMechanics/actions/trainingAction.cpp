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
    while (true)
    {
        handleClearScreen();
        printHeadline("Training Ground");

        std::cout << "Welcome to the Training Groud!\n";
        std::cout << "Here you can forge your legend and become a true hero!\n";
        std::cout << "\n";
        std::cout << "Train your attributes and unlock your full potential.\n";
        std::cout << "Ready to begin your journey to greatness?\n";


        printDivider(1, 2);
        std::cout << "What do you want to do?" << "\n";
        std::cout << "\n";
        std::cout << "1. Train your strength" << "\n";
        std::cout << "2. Train your defense" << "\n";
        std::cout << "3. Train your mana" << "\n";
        std::cout << "4. Train your energy" << "\n";
        std::cout << "5. Train your health" << "\n";
        std::cout << "6. Leave the training ground" << "\n";
        std::cout << "\n";
        std::cout << "Please enter your choice (1-6): ";

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
            return;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}