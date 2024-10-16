﻿#include <iostream>
#include <string>

#include "common/DataIO.h"
#include "player/Player.h"
#include "gameMechanics/PlayerChoice.h"
#include "player/CharacterClass.h"
#include "player/classes/Warrior.h"
#include "player/classes/Mage.h"
#include "player/classes/Rogue.h"
#include "common/Utility.h"
#include "common/GameConstants.h"
#include "gameMechanics/actions/menuActions/adventureAction.h"
#include "gameMechanics/actions/Actions.h"
#include "gameMechanics/actions/menuActions/innAction.h"
#include "initialization/SkillInitializer.h"
#include "gameMechanics/actions/menuActions/shopAction.h"
#include "color.hpp"

PlayerChoice showActions()
{
    while (true) 
    {
        handleClearScreen();
        std::cout << "What do you want to do?\n \n"
            << dye::yellow("1. ") << "View Character\n"
            << dye::yellow("2. ") << "View Inventory\n"
            << dye::yellow("3. ") << "View Equipment\n"
            << dye::yellow("4. ") << "View Journal\n"
            << dye::yellow("5. ") << "Rest\n"
            << dye::yellow("6. ") << "Training\n"
            << dye::yellow("7. ") << "Adventure\n"
            << dye::yellow("8. ") << "Shops\n"
            << dye::yellow("9. ") << "Craft\n"
            << dye::yellow("10. ") << "Inn\n"
            << dye::yellow("11. ") << "Save\n"
            << dye::yellow("12. ") << "Load\n"
            << dye::yellow("13. ") << "Exit\n \n"
            << "Enter your choice (1-12): ";

        int choice{getNumericInput()};

        if (choice >= static_cast<int>(PlayerChoice::ViewCharacter) &&
            choice <= static_cast<int>(PlayerChoice::Exit)) 
        {
            return static_cast<PlayerChoice>(choice);
        } 
        else if (choice > 6)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }
}

std::string getCharacterName()
{
    while (true)
    {
        printGetCharacterNameMessage();

        std::string playerName;
        std::getline(std::cin, playerName);

        if (playerName.empty()) 
        {
            std::cout << "Name can't be empty. Try again." << "\n";
        }
        else if (playerName.length() > 30) 
        {
            std::cout << "Name can't be longer than 30 characters. Try again." << "\n";
        }
        else 
        {
            return playerName;
        }
    }
}

CharacterClass getCharacterClass()
{
    while (true)
    {
        printDivider(1, 2);

        printGetCharacterClassMessage();

        int playerClass{ getNumericInput() };
        CharacterClass characterClass{};

        if (playerClass >= static_cast<int>(CharacterClass::Warrior) && playerClass <= static_cast<int>(CharacterClass::Mage)) 
        {
            characterClass = static_cast<CharacterClass>(playerClass);
            return characterClass;
        }
        else if (playerClass == 0)
        {
            continue;
        }
        else
        {
            std::cout << "Invalid selection! Please try again." << "\n";
        }
    }
}

Player* initializeGame()
{
   // printWelcomeMessage();

    //std::string name = getCharacterName();
    //CharacterClass characterClass = getCharacterClass();

    std::string name = "Jan";
    CharacterClass characterClass = CharacterClass::Mage;

    using namespace GameConstants::StartingStats;

    switch (characterClass)
    {
        case CharacterClass::Warrior:
            return new Warrior(name, HEALTH, WARRIOR_STRENGTH, MANA, ENERGY, MONEY, DEFENSE);
        case CharacterClass::Rogue:
            return new Rogue(name, HEALTH, ROGUE_STRENGTH, MANA, ENERGY, MONEY, DEFENSE);
        case CharacterClass::Mage:
            return new Mage(name, HEALTH, 100, MANA, ENERGY, MONEY, DEFENSE);
    }
    throw std::runtime_error("Unexpected character class");
}

int main()
{
    void adventureAction(Player & player);
    bool playerAlive = true;
    bool gameRunning = true;
    Player* player{ initializeGame() };
    SkillInitializer::initializeMageSkills(*player);

    while (playerAlive && gameRunning)
    {
        PlayerChoice playerChoice = showActions();
        switch (playerChoice)
        {
        case PlayerChoice::ViewCharacter:
            viewCharacterAction(*player);
            break;
        case PlayerChoice::ViewInventory:
            viewInventoryAction(*player);
            break;
        case PlayerChoice::ViewJournal:
            viewJournalAction(*player);
            break;
        case PlayerChoice::ViewEquipment:
            viewEquipmentAction(*player);
            break;
        case PlayerChoice::Rest:
            restAction(*player);
            break;
        case PlayerChoice::Training:
            trainingAction(*player);
            break;
        case PlayerChoice::Adventure:
            adventureAction(*player);
            break;
        case PlayerChoice::Shop:
            shopAction(*player);
            break;
        case PlayerChoice::Craft:
            //craftAction(*player);
            break;
        case PlayerChoice::Inn:
            innAction(*player);
            break;
        case PlayerChoice::Save:
            //saveGameAction(*player);
            break;
        case PlayerChoice::Load:
            //loadGameAction(*player);
            break;
        case PlayerChoice::Exit:
            gameRunning = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    delete player;
}