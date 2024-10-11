#include "gameMechanics/actions/menuActions/innAction.h"
#include "common/DataIO.h"
#include "common/Utility.h"
#include "quest/HuntingQuest.h"
#include <memory>
#include "quest/Journal.h"
#include "player/Player.h"

void getRewardFromCompletedQuests(Player& player)
{
	const std::vector<std::unique_ptr<Quest>>& completedQuests = player.getJournal().getCompletedQuests();
	
	for (auto& quest : completedQuests)
	{
		player.gainExperience(quest->getExperienceReward());
		player.gainGold(quest->getGoldReward());
		player.getJournal().finishQuest(quest.get());
	}
}

void handleCompleteQuest(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("Complete Quests");
		const std::vector<std::unique_ptr<Quest>>& quests = player.getJournal().getCompletedQuests();
		
		for (const auto& quest : quests)
		{
			std::cout << quest->getName() << "\n";
		}

		outputHelper({ "Hand in complete quests", "Return" });

		int playerChoice{ getNumericInput() };

		switch (playerChoice)
		{
		case 1:
			getRewardFromCompletedQuests(player);
		case 2:
			return;
		}
	}
}

void handleBlackBoard(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("The Black Board");
		std::cout << "1. Slash Wolves" << "\n";
		std::cout << "  Too many wolves aren't good for the village." << "\n";
		std::cout << "  Kill 5 Wolves" << "\n";
		std::cout << "\n";
		std::cout << "2. Collect 2 Bear Claws" << "\n";
		std::cout << "  The village needs bear claws for a special potion." << "\n";
		std::cout << "  Collect 2 Bear Claws" << "\n";

		printDivider(1, 2);
		outputHelper({ "Accept a new quest", "Complete Quest", "Return to menu" });

		int playerChoice{ getNumericInput() };
		Journal& journal = player.getJournal();

		switch (playerChoice)
		{
		case 1:
			player.getJournal().addQuest(std::make_unique<HuntingQuest>("Hunting Quest", "Kill the Wolves 2!", "You have to kill Wolves 2", 61, 62, std::vector<std::string>{}, "Wolf", 5));
			break;
		case 2:
			handleCompleteQuest(player);
			break;
		case 3:
			return;
		}
	}
}

void innAction(Player& player)
{
	while (true)
	{
		handleClearScreen();
		printHeadline("The Inn");
		std::cout << "Welcome in The Inn." << "\n";
		std::cout << "A place where other adventurers and adventures await you." << "\n";
		std::cout << "\n";
		std::cout << "You might want to take a look at the Black Board for some quests!" << "\n";

		printDivider(1, 2);

		outputHelper({ "Take a look at the Black Board", "Return to menu" });

		int playerChoice{ getNumericInput() };

		switch (playerChoice)
		{
		case 1:
			handleBlackBoard(player);
			break;
		case 2:
			return;
		}
	}
}