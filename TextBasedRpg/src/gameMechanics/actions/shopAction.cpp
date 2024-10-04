#include <iostream>
#include "gameMechanics/actions/shopAction.h"
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

		std::cout << "Where do you want to go?" << "\n";
		std::cout << "\n";
		std::cout << "1. Weapon Shop" << "\n";
		std::cout << "2. Armor Shop" << "\n";
		std::cout << "3. Potion Shop" << "\n";
		std::cout << "4. Skill Teacher" << "\n";
		std::cout << "5. Exit" << "\n";
		std::cout << "\n";
		std::cout << "Please enter your choice (1-5): ";

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