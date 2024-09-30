#pragma once
#include <string>
#include <vector>

class Quest
{
protected:
	const std::string m_name;
	const std::string m_description;
	const int m_experienceReward;
	const int m_goldReward;
	const std::vector<std::string> m_itemReward;

public:
	Quest(const std::string& name, const std::string& description, int experienceReward, int goldReward, std::vector<std::string> itemReward) :
		m_name(name),
		m_description(description),
		m_experienceReward(experienceReward),
		m_goldReward(goldReward),
		m_itemReward(itemReward)
	{}

	virtual ~Quest() {}

	virtual void printQuest() = 0;

	const std::string& getName() const { return m_name; }
	const std::string& getDescription() const { return m_description; }
	int getExperienceReward() const { return m_experienceReward; }
	int getGoldReward() const { return m_goldReward; }
	const std::vector<std::string>& getItemReward() const { return m_itemReward; }
};