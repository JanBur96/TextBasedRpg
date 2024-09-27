#include <limits>
#include <iostream>
#include <random>
#include <player/Player.h>

int getNumericInput()
{
    while (true)
    {
        int userInput;
        std::cin >> userInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            return 0;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return userInput;
    }
}

size_t generateRandomNumberInRange(size_t rangeFrom, size_t rangeTo)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distr(rangeFrom, rangeTo);

    return distr(gen);
}

int generateInnCost(Player& player, double locationFactor)
{
    int playerLevel{ player.getLevel() };
    int playerHealth{ player.getHealth() };
    int playerMaxHealth { player.getMaxHealth() };

    int baseCost = 10;
    int levelCost = playerLevel * 2;

    double healthPercentage = static_cast<double>(playerHealth) / playerMaxHealth;
    int healingCost = static_cast<size_t>((1.0 - healthPercentage) * 20);

    int totalCost{ baseCost + levelCost + healingCost };
    totalCost = static_cast<int>(totalCost * locationFactor);

    return totalCost;
}