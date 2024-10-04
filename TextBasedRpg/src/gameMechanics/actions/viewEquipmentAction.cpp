#include "gameMechanics/actions/viewEquipmentAction.h"
#include "common/Utility.h"
#include "common/DataIO.h"
#include "inventory/Inventory.h"
#include "inventory/Equippable.h"

void showEquippableItems(Player& player)
{
	while (true)
	{
		printHeadline("Equip Item");
		int itemIndex{ 1 };
		std::vector<Equippable> equippableItems{};

		for (const auto& item : player.getInventory().getItems())
		{
			if (dynamic_cast<const Equippable*>(item.get()) != nullptr)
			{
				equippableItems.push_back(*dynamic_cast<Equippable*>(item.get()));
				std::cout << itemIndex << "." << '\n';
				item->printItem();
				itemIndex++;
			}
		}

		printDivider(1, 2);
		std::cout << "Please enter the number of the item you want to equip: ";

		int itemToEquip{ getNumericInput() };
		equippableItems[itemToEquip - 1].equipItem(player);
	}
}

void viewEquipmentAction(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("View Equipment");

		std::cout << "Behold, brave adventurer, the gear that stands between you and certain doom!\n";
		std::cout << "Each piece tells a tale of your journey. What stories will you write today?\n";

		printDivider(1, 2);

		std::cout << "1. View Equipment in Inventory" << "\n";
		std::cout << "2. Equip Item" << "\n";
		std::cout << "3. Unequip Item" << "\n";
		std::cout << "4. Return to menu" << "\n";
		std::cout << "\n";
		std::cout << "Please enter your choice (1-4): ";

		int playerChoice{ getNumericInput() };

		switch (playerChoice)
		{
			case 1:
				std::cout << "case 1";
				break;
			case 2:
				handleClearScreen();
				showEquippableItems(player);
				break;
			case 3:
				std::cout << "case 3";
				break;
			case 4:
				return;
		}
	}
}