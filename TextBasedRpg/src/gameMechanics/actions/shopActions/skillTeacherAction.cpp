#include "gameMechanics/actions/shopActions/skillTeacherAction.h"
#include "common/Utility.h"
#include "player/SkillRepository.h"
#include "shared/Skill.h"
#include "common/DataIO.h"

std::vector<Skill> vectorLevelFilter(std::vector<Skill>& skillsToLearn, int playerLevel)
{
	std::vector<Skill> filteredSkills{};

	for (const Skill& skill : skillsToLearn)
	{
		if (skill.getSkillUnlockLevel() <= playerLevel)
		{
			filteredSkills.push_back(skill);
		}
	}

	return filteredSkills;
}

void showSkillsToLearn(Player& player)
{
	while (true)
	{
		std::vector<Skill> skillsToLearn{ SkillRepository::getAllSkills() };
		std::vector<Skill> filteredSkills{vectorLevelFilter(skillsToLearn, player.getLevel())};
		int index{ 1 };

		handleClearScreen();

		if (filteredSkills.size() < 1)
		{
			std::cout << "No skills available to learn." << "\n";

			printDivider(1, 2);

			std::cout << "Press 1 to return to the shopping row." << "\n";
			int input{ getNumericInput() };

			if (input == 1)
			{
				return;
			}
		}
		else {
			std::cout << "Skills available to learn: " << "\n";

			for (const Skill& skill : filteredSkills)
			{
				std::cout << index << "." << "\n";
				std::cout << "  Skill Name: " << skill.getName() << '\n';
				std::cout << "  Skill Unlock Level: " << skill.getSkillUnlockLevel() << '\n';
				std::cout << "  Skill Unlock Cost: " << skill.getSkillUnlockCost() << '\n';
				std::cout << "  Damage: " << skill.getDamage() << '\n';
				std::cout << "  Mana Cost: " << skill.getManaCost() << '\n';
				index++;
			}

			std::cout << "Please enter the number of the skill you want to learn: ";
			int skillToLearnIndex{ getNumericInput() };
		}
	}
}

void skillTeacherAction(Player& player)
{
	handleClearScreen();
	printHeadline("Skill Teacher");
	std::cout << "Welcome to the Skill Teacher!" << "\n";
	std::cout << "Here you can learn new skills to help you on your journey." << "\n";

	printDivider(1, 2);

	std::cout << "What would you like to do?" << "\n";
	std::cout << "1. Learn a new skill" << "\n";
	std::cout << "2. Exit" << "\n";

	int skillTeacherDecision{ getNumericInput() };

	switch (skillTeacherDecision)
	{
		case 1:
			{
				showSkillsToLearn(player);
				break;
			}
		default:
			return;
	}

}