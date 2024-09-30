#include "gameMechanics/actions/viewJournalAction.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void viewJournalAction(Player& player)
{
	while (true)
	{
		printDivider(1, 2);
		std::cout << "Journal" << '\n';
		std::cout << "1. View Open Quests" << '\n';
		std::cout << "2. View Completed Quests" << '\n';
		std::cout << "3. Back to main menu" << '\n';

		int viewJournalChoice{ getNumericInput() };

		switch (viewJournalChoice)
		{
			case 1:
			{
				const std::vector<std::unique_ptr<Quest>>& openQuests {player.getJournal().getOpenQuests() };

				for (const auto& quest : openQuests)
				{
					quest->printQuest();
				}

				break;
			}
			case 2:
			{

				break;
			}
			case 3:
				return;
			default:
			{
				std::cout << "Invalid choice. Please enter a number between 1 and 3." << '\n';
			}
		}
	}
}
