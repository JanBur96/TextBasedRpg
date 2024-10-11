#include <iostream>
#include "gameMechanics/actions/menuActions/shopAction.h"
#include "common/Utility.h";
#include "gameMechanics/actions/shopActions/skillTeacherAction.h"
#include "common/DataIO.h"

void shopAction(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("Shops");
		std::cout << "Welcome to the bustling Shopping Row!\n";
		std::cout << "Where every purchase is an adventure.\n";
		printDivider(1, 2);

		outputHelper({ "Weapon Shop", "Armor Shop", "Potion Shop", "Skill Teacher", "Return to menu" }, true);

		int shopDecision{ getNumericInput() };

		switch (shopDecision)
		{
			case 1:
				//openWeaponShop()
				break;
			case 2:
				//openArmorShop()
				break;
			case 3:
				//openPotionShop()
				break;
			case 4:
				skillTeacherAction(player);
				break;
			case 5:
				return;
			default:
				std::cout << "Invalid choice. Please enter a number between 1 and 5." << "\n";
		}
	}
}