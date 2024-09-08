#include <iostream>
#include <string>

#include "DataIO.h"
#include "Player.h"
#include "PlayerChoice.h"
#include "CharacterClass.h"
#include "Actions.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Utility.h"
#include "GameConstants.h"

PlayerChoice showActions()
{
    while (true) 
    {
        printDivider(1, 2, false);
        std::cout << "What do you want to do?\n"
            << "1. View Character\n"
            << "2. Show Inventory\n"
            << "3. Rest\n"
            << "4. Training\n"
            << "5. Adventure\n"
            << "6. Exit\n"
            << "Enter your choice (1-6): ";

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
            std::cout << "Name can't be empty. Try again." << std::endl;
        }
        else if (playerName.length() > 30) 
        {
            std::cout << "Name can't be longer than 30 characters. Try again." << std::endl;
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
            std::cout << "Invalid selection! Please try again." << std::endl;
        }
    }
}

Player* initializeGame()
{
    printWelcomeMessage();

    std::string name = getCharacterName();
    CharacterClass characterClass = getCharacterClass();

    using namespace GameConstants::StartingStats;

    switch (characterClass)
    {
        case CharacterClass::Warrior:
            return new Warrior(name, HEALTH, WARRIOR_STRENGTH, MANA, ENERGY, MONEY, DEFENSE, STARTING_LOCATION);
        case CharacterClass::Rogue:
            return new Rogue(name, HEALTH, ROGUE_STRENGTH, MANA, ENERGY, MONEY, DEFENSE, STARTING_LOCATION);
        case CharacterClass::Mage:
            return new Mage(name, HEALTH, MAGE_STRENGTH, MANA, ENERGY, MONEY, DEFENSE, STARTING_LOCATION);
        }
    throw std::runtime_error("Unexpected character class");
}

int main()
{
    bool playerAlive = true;
    bool gameRunning = true;
    Player* player{ initializeGame() };

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
            case PlayerChoice::Rest:
                restAction(*player);
                break;
            case PlayerChoice::Training:
                trainingAction(*player);
                break;
            case PlayerChoice::Adventure:
                adventureAction(*player);
                break;
            case PlayerChoice::Exit:
                gameRunning = false;
                break;
        }
    }

    delete player;
}