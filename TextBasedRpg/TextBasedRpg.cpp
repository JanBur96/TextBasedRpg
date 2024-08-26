// TextBasedRpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "DataIO.h"
#include "Player.h"
#include "PlayerChoice.h"
#include "CharacterClass.h"
#include "Actions.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "EnemyFactory.h"

PlayerChoice showActions()
{
    while (true) {
        printDivider(1, 2, true);

        std::cout << "What do you want to do?\n"
            << "1. View Character\n"
            << "2. Show Inventory\n"
            << "3. Rest\n"
            << "4. Training\n"
            << "5. Adventure\n"
            << "6. Exit\n"
            << "Enter your choice (1-6): ";

        int choice;
        std::cin >> choice;

        if (choice >= static_cast<int>(PlayerChoice::ViewCharacter) &&
            choice <= static_cast<int>(PlayerChoice::Exit)) {
            return static_cast<PlayerChoice>(choice);
        }

        std::cout << "Invalid choice. Please try again.\n";
    }
}

std::string getCharacterName()
{
    std::cout << "How is your character called?" << std::endl;
    std::string playerName;
    std::getline(std::cin, playerName);

    return playerName;
}

CharacterClass getCharacterClass()
{
    printDivider(1, 2);
    std::cout << "Please choose a character class for your adventure:" << std::endl;
    std::cout << "1. Warrior \n" << "2. Rogue \n" << "3. Mage \n";
    std::cout << "Who do you select (type 1-3): ";
    int playerClass;
    std::cin >> playerClass;
    CharacterClass characterClass{};

    if (playerClass >= static_cast<int>(CharacterClass::Warrior) &&
        playerClass <= static_cast<int>(CharacterClass::Mage)) {
        characterClass = static_cast<CharacterClass>(playerClass);
    }

    return characterClass;
}

Player* initializeGame()
{
    welcomeMessage();

    std::string name = getCharacterName();
    CharacterClass characterClass = getCharacterClass();

    Player* player = nullptr;

    switch (characterClass)
    {

    case CharacterClass::Warrior:
        player = new Warrior(name, 100, 15, 100, 50, 15, 10, "Starting Town");
        break;
    case CharacterClass::Rogue:
        player = new Rogue(name, 100, 15, 100, 50, 15, 10, "Starting Town");
        break;
    case CharacterClass::Mage:
        player = new Mage(name, 100, 15, 100, 50, 15, 10, "Starting Town");
        break;
    default:
        std::cout << "Invalid class selected. Defaulting to Warrior." << std::endl;
    }

    return player;
}

int main()
{
    bool playerAlive = true;
    bool gameRunning = true;
    Player* player{ initializeGame() };

    while (playerAlive && gameRunning)
    {
        PlayerChoice playerChoice = showActions();

        switch (playerChoice) {
        case PlayerChoice::ViewCharacter:
        {
            viewCharacterAction(*player);
            break;
        }
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
        {
            adventureAction(*player);
            break;
        }
        case PlayerChoice::Exit:
            gameRunning = false;
            break;
        }
    }

    delete player;
}