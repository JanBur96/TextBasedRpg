#include <iostream>
#include <chrono>
#include "DataIO.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif


void printSlowly(const std::string& text, int milliseconds = 1) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    std::cout << std::endl;
}

void printWelcomeMessage() {
    std::cout << "\n\n";
    std::cout << "****************************************************\n";
    std::cout << "*                                                  *\n";
    std::cout << "*          Welcome to the Mystical Realm of        *\n";
    std::cout << "*                                                  *\n";
    std::cout << "*                 Dalil Quest                      *\n";
    std::cout << "*                                                  *\n";
    std::cout << "*          Where Legends Are Born and Destiny      *\n";
    std::cout << "*                 Awaits the Brave!                *\n";
    std::cout << "*                                                  *\n";
    std::cout << "****************************************************\n\n";

    printSlowly("Prepare yourself, brave adventurer...");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    printSlowly("Your epic journey is about to begin!");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\n---------------------------------------------------- \n\n";
}

void printGetCharacterNameMessage()
{
    std::cout << "A new adventure awaits you!" << std::endl;
    std::cout << "How is your character called?" << std::endl;
    std::cout << "Enter your character's name (max. 30 characters): ";
    std::cout << std::flush;
}

void printGetCharacterClassMessage()
{
    std::cout << "A hero needs a specialization!" << std::endl;
    std::cout << "Choose your character's class:" << std::endl;
    std::cout << "1. Warrior \n" << "2. Rogue \n" << "3. Mage \n";
    std::cout << "Who do you select (type 1-3): ";
    std::cout << std::flush;
}

void printDivider(int emptyLinesBefore, int emptyLinesAfter, bool clearScreen)
{

    if (clearScreen) { handleClearScreen(); };

    if (emptyLinesBefore) 
    {
        for (int i{ 0 }; i < emptyLinesBefore; i++)
        {
            std::cout << std::endl;
        }
    }

    std::cout << "----------------------------------------------------";

    if (emptyLinesAfter)
    {
        for (int i{ 0 }; i < emptyLinesAfter; i++)
        {
            std::cout << std::endl;
        }
    }
}

void handleClearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}