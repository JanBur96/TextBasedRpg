#include "gameMechanics/actions/restAction.h"
#include "common/Utility.h"
#include "common/DataIO.h"

void restAction(Player& player)
{
    while (true)
    {
        printDivider(1, 2);

        int cost{ generateInnCost(player, 2) };

        std::cout << "Welcome in Isabels Inn!" << std::endl;
        std::cout << "Staying a night costs " << cost << " Gold." << std::endl;

        printDivider(1, 2);

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Stay for the night" << std::endl;
        std::cout << "2. Leave the inn" << std::endl;
        std::cout << "Enter your choice (1-2):" << std::endl;

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