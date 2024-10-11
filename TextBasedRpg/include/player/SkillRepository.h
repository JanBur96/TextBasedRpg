#pragma once
#include "player/Skill.h"
#include <vector>

class SkillRepository
{
private:
	static std::vector<Skill> g_skills;

public:
	static const std::vector<Skill>& getAllSkills();
	static const Skill* getSkillByName(const std::string& name);
};