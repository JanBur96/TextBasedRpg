#pragma once
#include <vector>

void printSlowly(const std::string& text, int milliseconds);

void printWelcomeMessage();

void printGetCharacterNameMessage();

void printGetCharacterClassMessage();

void printDivider(int emptyLinesBefore, int emptyLinesAfter, bool clearScreen = false);

void handleClearScreen();

void printHeadline(std::string text);

void printListing(std::string);

void outputHelper(std::vector<std::string>, bool isGo = false);