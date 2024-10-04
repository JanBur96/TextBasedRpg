#pragma once
#include "Quest.h"
#include <string>

class HuntingQuest : public Quest
{
private:
    const std::string m_monsterToKill;
    const int m_monsterToKillCount; 
    int m_monsterKilled = 0;

public:
    HuntingQuest(const std::string questType, const std::string& name, const std::string& description, int experienceReward, int goldReward, std::vector<std::string> itemReward, std::string monsterToKill, int monsterToKillCount) :
        Quest(questType, name, description, experienceReward, goldReward, std::move(itemReward)),
        m_monsterToKill(monsterToKill),
        m_monsterToKillCount(monsterToKillCount)
    {}

	~HuntingQuest() {}

    void printQuest() override;

	std::string getMonsterToKill() const { return m_monsterToKill; }
	int getMonsterToKillCount() const { return m_monsterToKillCount; }
	int getMonsterKilled() const { return m_monsterKilled; }
    bool isQuestComplete() const { return m_monsterKilled >= m_monsterToKillCount; }

	void setMonsterKilled(int monsterKilled) { m_monsterKilled = monsterKilled; }
	void incrementMonsterKilled() { m_monsterKilled++; }
};