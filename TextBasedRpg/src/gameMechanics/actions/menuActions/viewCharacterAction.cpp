#include <iostream>
#include "player/Player.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void viewCharacterAction(Player& player)
{
    while (true)
    {
        handleClearScreen();
        printHeadline("View Character");
        std::cout << "Name: " << player.getName() << "\n";
        std::cout << "Class: " << player.getCharacterClass() << "\n";
        std::cout << "Level: " << player.getLevel() << "\n" << "\n";

        std::cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << "\n";
        std::cout << "Mana: " << player.getMana() << "/" << player.getMaxMana() << "\n";
        std::cout << "Strength: " << player.getStrength() << "\n";
        std::cout << "Defense: " << player.getDefense() << "\n";
        std::cout << "Experience: " << player.getExperience() << "/" << player.getExperienceForNextLevel() << "\n";
        std::cout << "Energy: " << player.getEnergy() << "/" << player.getMaxEnergy() << "\n" << "\n";

        std::cout << "Skills: " << "\n";
        for (Skill skill : player.getSkills())
        {
            std::cout << "  Name: " << skill.getName() << "\n";
            std::cout << "  Level: " << skill.getSkillLevel() << "\n";
            std::cout << "  Damage: " << skill.getDamage() << "\n";
            std::cout << "  Mana cost: " << skill.getManaCost() << "\n";
        }
        printDivider(1, 2);

        outputHelper({ "Back to main menu" });

        int viewCharacterChoice{ getNumericInput() };

        if (viewCharacterChoice == 1)
        {
            return;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << "\n";
        }
    }
}