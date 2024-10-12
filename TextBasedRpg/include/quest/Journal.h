#pragma once
#include <vector>
#include <memory>
#include "Quest.h"

class Journal
{
private:
    std::vector<std::unique_ptr<Quest>> m_openQuests;
    std::vector<std::unique_ptr<Quest>> m_completedQuests;
    std::vector<std::unique_ptr<Quest>> m_archivedQuests;

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

    void finishQuest(Quest* quest)
	{
		auto it = std::find_if(m_completedQuests.begin(), m_completedQuests.end(),
			[quest](const std::unique_ptr<Quest>& q) { return q.get() == quest; });

		if (it != m_completedQuests.end()) {
			m_archivedQuests.push_back(std::move(*it));
			m_completedQuests.erase(it);
		}
	}

    const std::vector<std::unique_ptr<Quest>>& getOpenQuests() const { return m_openQuests; }
    const std::vector<std::unique_ptr<Quest>>& getCompletedQuests() const { return m_completedQuests; }
    const std::vector<std::unique_ptr<Quest>>& getArchivedQuests() const { return m_archivedQuests; }
};