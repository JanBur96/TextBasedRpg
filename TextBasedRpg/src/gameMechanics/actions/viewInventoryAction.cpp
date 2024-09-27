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
            std::cout << "Gold: " << player.getGold() << std::endl;
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