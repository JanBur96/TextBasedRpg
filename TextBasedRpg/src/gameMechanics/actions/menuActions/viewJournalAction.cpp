#include "gameMechanics/actions/menuActions/viewJournalAction.h"
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

		outputHelper({ "View Open Quests", "View Completed Quests", "Back to main menu" });

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

				handleClearScreen();
				printHeadline("Open Quests");

				for (size_t i = 0; i < openQuests.size(); ++i)
				{
					std::cout << i + 1 << ". ";
					openQuests[i]->printQuest();
					std::cout << '\n';
				}

				printDivider(1, 2);

				outputHelper({ "Return" });

				switch (getNumericInput())
				{
				case 1:
					return;
				default:
					std::cout << "Invalid choice. Please enter a valid number." << '\n';
				}

				break;
			}
			case 2:
			{
				const std::vector<std::unique_ptr<Quest>>& completedQuests {player.getJournal().getCompletedQuests() };

				handleClearScreen();
				printHeadline("Completed Quests");

				if (completedQuests.size() < 1) {
					std::cout << "No completed quests." << '\n';
				}

				for (const auto& quest : completedQuests)
				{
					quest->printQuest();
				}

				printDivider(1, 2);

				outputHelper({ "Return" });

				switch (getNumericInput())
				{
				case 1:
					return;
				default:
					std::cout << "Invalid choice. Please enter a valid number." << '\n';
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
