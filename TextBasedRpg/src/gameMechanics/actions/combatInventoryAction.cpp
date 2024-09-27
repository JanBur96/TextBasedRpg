#include "gameMechanics/actions/combatInventoryAction.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void combatInventoryAction(Player& player)
{
    Inventory& playerInventory{ player.getInventory() };
    const std::vector<std::unique_ptr<InventoryItem>>& inventoryItems{ playerInventory.getItems() };

    if (inventoryItems.empty())
    {
        printDivider(1, 2);
        std::cout << "Your inventory is empty." << '\n';
        return;
    }
    else
    {
        while (true)
        {
            printDivider(1, 2);
            int itemIndex{ 1 };
            std::cout << "View Inventory" << '\n';
            std::cout << "Inventory: " << '\n';
            for (const auto& item : player.getInventory().getItems())
            {
                std::cout << itemIndex << "." << '\n';
                item->printItem();
                itemIndex++;
            }

            printDivider(1, 2);

            std::cout << "What do you want to do?" << '\n';
            std::cout << "1. Use item" << '\n';
            std::cout << "2. Return to battle actions" << '\n';

            int viewInventoryChoice{ getNumericInput() };

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
                return;
            }
        }
    }
}
    }