#include <limits>
#include <iostream>
#include <random>

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

int generateRandomNumberInRange(int rangeFrom, int rangeTo)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(rangeFrom, rangeTo);

    return distr(gen);
}