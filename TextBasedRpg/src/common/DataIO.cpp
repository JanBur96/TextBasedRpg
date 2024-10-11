#include <iostream>
#include <chrono>
#include "common/DataIO.h"
#include "color.hpp"
#include <vector>

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
    std::cout << '\n';
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
    std::cout << "A new adventure awaits you!" << '\n';
    std::cout << "How is your character called?" << '\n';
    std::cout << "Enter your character's name (max. 30 characters): ";
    std::cout << std::flush;
}

void printGetCharacterClassMessage()
{
    std::cout << "A hero needs a specialization!" << '\n';
    std::cout << "Choose your character's class:" << '\n';
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
            std::cout << '\n';
        }
    }

    std::cout << dye::aqua("----------------------------------------------------");

    if (emptyLinesAfter)
    {
        for (int i{ 0 }; i < emptyLinesAfter; i++)
        {
            std::cout << '\n';
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

void printHeadline(std::string text)
{
    std::cout << dye::yellow(text) << "\n";
    std::cout << dye::aqua(std::string(text.length(), '-')) << "\n \n";
}

void printListing(std::string text)
{
    std::cout << dye::yellow(text) << "\n";
}

void outputHelper(std::vector<std::string> options, bool isGo)
{
    int counter{ 1 };

    if (isGo)
    {
		std::cout << "Where do you want to go?" << "\n";
	}
    else
    {
        std::cout << "What do you want to do?" << "\n";
    }

    for (const std::string& option : options)
    {
        std::cout << counter << ". " << option << "\n";
        counter++;
    }

    std::cout << "\n";

    if (options.size() > 1)
    {
		std::cout << "Please enter your choice (" << 1 << "-" << options.size() << "): ";
	}
	else
	{
		std::cout << "Please enter your choice (1): ";
	}
}