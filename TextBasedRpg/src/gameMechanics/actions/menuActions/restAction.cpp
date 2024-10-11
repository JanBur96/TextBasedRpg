#include "gameMechanics/actions/menuActions/restAction.h"
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

        outputHelper({ "Stay for the night", "Leave the inn" });

        int restChoice{ getNumericInput() };

        if (restChoice == 1)
        {
            if (player.payGold(cost))
            {
				player.rest();
                std::cout << "You slept well and are well rested now." << "\n";
			}
			else
			{
				std::cout << "You don't have enough Gold to stay here." << "\n";
			}
        }
        else if (restChoice == 2) {
            return;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << "\n";
        }
    }
}