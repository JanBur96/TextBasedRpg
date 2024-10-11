#include "gameMechanics/actions/menuActions/viewEquipmentAction.h"
#include "common/Utility.h"
#include "common/DataIO.h"
#include "inventory/Inventory.h"
#include "inventory/Equippable.h"

void handleViewEquippable(Player& player)
{
	while (true)
	{
		printHeadline("View Equippable Items");

		int itemIndex{ 1 };
		for (const auto& item : player.getInventory().getItems())
		{
			if (auto* equippable = dynamic_cast<Equippable*>(item.get()))
			{
				std::cout << itemIndex << "." << '\n';
				equippable->printItem();
				itemIndex++;
			}
		}

		printDivider(1, 2);

		outputHelper({ "Return to menu" });

		int playerChoice{ getNumericInput() };
		if (playerChoice == 1)
		{
			return;
		}
	}
}

void handleEquipItem(Player& player)
{
    while (true)
    {
        printHeadline("Equip Item");
        int itemIndex{ 1 };
        std::vector<Equippable*> equippableItems{};
        for (const auto& item : player.getInventory().getItems())
        {
            if (auto* equippable = dynamic_cast<Equippable*>(item.get()))
            {
                equippableItems.push_back(equippable);
                std::cout << itemIndex << "." << '\n';
                equippable->printItem();
                itemIndex++;
            }
        }
        printDivider(1, 2);
        std::cout << "Please enter the number of the item you want to equip or 0 + Enter to return: ";
        int itemToEquip{ getNumericInput() };

		if (itemToEquip == 0)
		{
			return;
		}

        equippableItems[itemToEquip - 1]->equipItem(player);
        return;
    }
}

void handleUnequipItem(Player& player)
{
	printHeadline("Unequip Item");

	player.getEquip().printEquip();

	printDivider(1, 2);
	outputHelper({ "Unequip Weapon", "Unequip Armor", "Unequip Accessory", "Return to menu"});

	int slotToUnequip{getNumericInput()};

	switch (slotToUnequip)
	{
		case 1:
			player.getEquip().unequipWeapon(player.getEquip().getWeapon(), player);
			return;
		case 2:
			player.getEquip().unequipArmor(player.getEquip().getArmor(), player);
			return;
		case 3:
			player.getEquip().unequipAccessory(player.getEquip().getAccessory(), player);
			return;
		case 4:
			return;
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
		std::cout << "\n";
		player.getEquip().printEquip();

		printDivider(1, 2);

		outputHelper({ "View Equipment in Inventory", "Equip Item", "Unequip Item", "Return to menu" });

		int playerChoice{ getNumericInput() };

		switch (playerChoice)
		{
			case 1:
				handleViewEquippable(player);
				break;
			case 2:
				handleClearScreen();
				handleEquipItem(player);
				break;
			case 3:
				handleClearScreen();
				handleUnequipItem(player);
				break;
			case 4:
				return;
		}
	}
}