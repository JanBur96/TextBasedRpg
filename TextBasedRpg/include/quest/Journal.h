#pragma once
#include <vector>
#include <memory>
#include "Quest.h"

class Journal
{
private:
    std::vector<std::unique_ptr<Quest>> m_openQuests;
    std::vector<std::unique_ptr<Quest>> m_completedQuests;

public:
    void addQuest(std::unique_ptr<Quest> quest)
    {
        m_openQuests.push_back(std::move(quest));
    }

    void completeQuest(Quest* quest)
    {
        auto it = std::find_if(m_openQuests.begin(), m_openQuests.end(),
            [quest](const std::unique_ptr<Quest>& q) { return q.get() == quest; });

        if (it != m_openQuests.end()) {
            m_completedQuests.push_back(std::move(*it));
            m_openQuests.erase(it);
        }
    }

    const std::vector<std::unique_ptr<Quest>>& getOpenQuests() const { return m_openQuests; }
    const std::vector<std::unique_ptr<Quest>>& getCompletedQuests() const { return m_completedQuests; }
};