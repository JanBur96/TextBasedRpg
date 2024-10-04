#include "player/SkillRepository.h"
#include <vector>
#include <string>
#include "shared/Skill.h"

//std::string m_name;
//int m_skillLevel;
//int m_skillUnlockLevel;
//int m_skillUnlockCost;
//int m_damage;
//int m_manaCost;

std::vector<Skill> SkillRepository::g_skills = {
	Skill("Blizzard", 1, 3, 300, 25, 15),
};

const std::vector<Skill>& SkillRepository::getAllSkills()
{
	return g_skills;
}

const Skill* SkillRepository::getSkillByName(const std::string& name)
{
	for (const Skill& skill : g_skills)
	{
		if (skill.getName() == name)
		{
			return &skill;
		}
	}

	return nullptr;
}