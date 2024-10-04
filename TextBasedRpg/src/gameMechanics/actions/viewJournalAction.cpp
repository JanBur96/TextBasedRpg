#include "gameMechanics/actions/viewJournalAction.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void viewJournalAction(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("Journal");

		std::cout << "You got " << player.getJournal().getOpenQuests().size() << " open quest(s)." << "\n";
		std::cout << "You got " << player.getJournal().getCompletedQuests().size() << " completed quest(s)." << "\n";
		std::cout << "\n";
		std::cout << "You've discovered 22 different kind of monsters" << "\n";

		printDivider(1, 2);

		std::cout << "1. View Open Quests" << '\n';
		std::cout << "2. View Completed Quests" << '\n';
		std::cout << "3. Back to main menu" << '\n';

		std::cout << "Please enter your choice (1-3): ";

		int viewJournalChoice{ getNumericInput() };

		switch (viewJournalChoice)
		{
			case 1:
			{
				const std::vector<std::unique_ptr<Quest>>& openQuests {player.getJournal().getOpenQuests() };

				if (openQuests.size() < 1) {
					std::cout << "No open quests." << '\n';
					break;
				}

				for (const auto& quest : openQuests)
				{
					quest->printQuest();
				}

				break;
			}
			case 2:
			{
				const std::vector<std::unique_ptr<Quest>>& completedQuests {player.getJournal().getCompletedQuests() };

				if (completedQuests.size() < 1) {
					std::cout << "No completed quests." << '\n';
					break;
				}	

				for (const auto& quest : completedQuests)
				{
					quest->printQuest();
				}

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
