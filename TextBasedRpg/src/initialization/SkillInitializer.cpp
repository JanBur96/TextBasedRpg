#include "initialization/SkillInitializer.h"


void SkillInitializer::initializeMageSkills(Player& player)
{
	player.addSkill(Skill("Fireball", 1, 1, 0, 18, 10));
}