#include "quest/CollectQuest.h"
#include <iostream>
#include "common/DataIO.h"
#include "color.hpp"
#include "inventory/itemMapper.h"
#include "player/Player.h"

void CollectQuest::printQuest(Player& player)
{
	std::cout << dye::yellow(m_name) << "\n";
	std::cout << "   Description: " << m_description << "\n";
	std::cout << "   Experience Reward: " << m_experienceReward << "\n";
	std::cout << "   Item to obtain: " << itemTypeToString(m_itemToCollect) << "\n";
	std::cout << "   Item to obtain count: " << m_itemToCollectCount << "\n";
	std::cout << "   Items obtained: " << getItemsCollected(player) << "\n";
	std::cout << "   Gold Reward: " << m_goldReward << "\n";
	std::cout << "   Item Reward(s): ";
	for (const auto& item : m_itemReward)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
}

int CollectQuest::getItemsCollected(Player& player)
{
	auto& inventory = player.getInventory();
	int itemsCollected = 0;

	for (const auto& item : inventory.getItems())
	{
		if (item->getType() == m_itemToCollect)
		{
			itemsCollected += item->getQuantity();
		}
	}

	return itemsCollected;
}