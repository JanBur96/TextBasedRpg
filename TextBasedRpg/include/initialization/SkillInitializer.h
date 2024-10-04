#pragma once
#include "shared/Skill.h"
#include "player/Player.h"

namespace SkillInitializer {
    void initializeCommonSkills(Player& player);
    void initializeMageSkills(Player& player);
    void initializeWarriorSkills(Player& player);
    void initializeRogueSkills(Player& player);
}