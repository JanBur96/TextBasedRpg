#pragma once
#include "Quest.h"
#include <string>
#include "inventory/ItemType.h"
#include "player/Player.h"

class CollectQuest : public Quest
{
private:
    const ItemType m_itemToCollect;
    const int m_itemToCollectCount;
    int m_itemsCollected = 0;

public:
    CollectQuest(const std::string questType, const std::string& name, const std::string& description, int experienceReward, int goldReward, std::vector<std::string> itemReward, ItemType itemToCollect, int itemToCollectCount) :
        Quest(questType, name, description, experienceReward, goldReward, std::move(itemReward)),
        m_itemToCollect(itemToCollect),
        m_itemToCollectCount(itemToCollectCount)
    {}

    ~CollectQuest() {}

    void printQuest() override {};
    void printQuest(Player&);

    ItemType getItemToCollect() const { return m_itemToCollect; }
    int getItemToCollectCount() const { return m_itemToCollectCount; }
    int getItemsCollected(Player&);
    bool isQuestComplete() const { return m_itemsCollected >= m_itemToCollectCount; }

    void setItemsCollected(int itemsCollected) { m_itemsCollected = itemsCollected; }
    void incrementItemsCollected() { m_itemsCollected++; }
};