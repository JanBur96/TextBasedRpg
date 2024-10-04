#include "gameMechanics/actions/viewInventoryAction.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void viewInventoryAction(Player& player)
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
            int itemIndex{ 1 };
            handleClearScreen();
            printHeadline("View Inventory");
            std::cout << "Gold: " << player.getGold() << '\n';
            std::cout << "Inventory: " << '\n';
            for (const auto& item : player.getInventory().getItems())
            {
                std::cout << itemIndex << "." << '\n';
                item->printItem();
                itemIndex++;
            }

            printDivider(1, 2);

            std::cout << "1. Use item" << '\n';
            std::cout << "2. Drop item" << '\n';
            std::cout << "3. Back to main menu" << '\n';
            std::cout << "Please enter your choice (1-3): ";

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