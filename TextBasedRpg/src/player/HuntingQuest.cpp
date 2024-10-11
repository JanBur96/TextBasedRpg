#include "quest/HuntingQuest.h"
#include <iostream>
#include "common/DataIO.h"
#include "color.hpp"

void HuntingQuest::printQuest()
{
	std::cout << dye::yellow(m_name) << "\n";
	std::cout << "   Description: " << m_description << "\n";
	std::cout << "   Experience Reward: " << m_experienceReward << "\n";
	std::cout << "   Monster to kill: " << m_monsterToKill << "\n";
	std::cout << "   Monster to kill count: " << m_monsterToKillCount << "\n";
	std::cout << "   Monster killed: " << m_monsterKilled << "\n";
	std::cout << "   Gold Reward: " << m_goldReward << "\n";
	std::cout << "   Item Reward(s): ";
	for (const auto& item : m_itemReward)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
}