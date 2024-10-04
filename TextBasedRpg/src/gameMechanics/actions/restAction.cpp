#include "gameMechanics/actions/restAction.h"
#include "common/Utility.h"
#include "common/DataIO.h"

void restAction(Player& player)
{
    while (true)
    {
        int cost{ generateInnCost(player, 2) };

        handleClearScreen();
        printHeadline("Inn");

        std::cout << "Welcome to Isabels Inn!" << "\n";
        std::cout << "Staying a night costs " << cost << " gold." << "\n";

        printDivider(1, 2);

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Stay for the night" << std::endl;
        std::cout << "2. Leave the inn" << std::endl;
        std::cout << "Please enter your choice (1-2): ";

        int restChoice{ getNumericInput() };

        if (restChoice == 1)
        {
            if (player.payGold(cost))
            {
				player.rest();
                std::cout << "You slept well and are well rested now." << std::endl;
			}
			else
			{
				std::cout << "You don't have enough Gold to stay here." << std::endl;
			}
        }
        else if (restChoice == 2) {
            return;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}