#include "player/HuntingQuest.h"
#include <iostream>
#include "common/DataIO.h"

void HuntingQuest::printQuest()
{
	handleClearScreen();

	std::cout << "Name: " << m_name << "\n";
	std::cout << "Description: " << m_description << "\n";
	std::cout << "Experience Reward: " << m_experienceReward << "\n";
	std::cout << "Gold Reward: " << m_goldReward << "\n";
	std::cout << "Item Reward: ";
	for (const auto& item : m_itemReward)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
	std::cout << "Monster to kill: " << m_monsterToKill << "\n";
	std::cout << "Monster to kill count: " << m_monsterToKillCount << "\n";
	std::cout << "Monster killed: " << m_monsterKilled << "\n";
}