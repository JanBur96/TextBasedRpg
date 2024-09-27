#include <iostream>
#include "player/Player.h"
#include "common/DataIO.h"
#include "common/Utility.h"

void viewCharacterAction(Player& player)
{
    while (true)
    {
        printDivider(1, 2, true);
        std::cout << "View Character" << std::endl;
        std::cout << "Name: " << player.getName() << std::endl;
        std::cout << "Class: " << player.getCharacterClass() << std::endl;
        std::cout << "Level: " << player.getLevel() << std::endl;
        std::cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << std::endl;
        std::cout << "Mana: " << player.getMana() << "/" << player.getMaxMana() << std::endl;
        std::cout << "Strength: " << player.getStrength() << std::endl;
        std::cout << "Defense: " << player.getDefense() << std::endl;
        std::cout << "Experience: " << player.getExperience() << "/" << player.getExperienceForNextLevel() << std::endl;
        std::cout << "Skills: " << std::endl;
        for (Skill skill : player.getSkills())
        {
            std::cout << "  Name: " << skill.getName() << std::endl;
            std::cout << "  Level: " << skill.getLevel() << std::endl;
            std::cout << "  Damage: " << skill.getDamage() << std::endl;
            std::cout << "  Mana cost: " << skill.getManaCost() << std::endl;
        }
        std::cout << "Energy: " << player.getEnergy() << "/" << player.getMaxEnergy() << std::endl;
        printDivider(1, 2);

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Back to main menu" << std::endl;

        int viewCharacterChoice{ getNumericInput() };

        if (viewCharacterChoice == 1)
        {
            return;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}