#pragma once
#include "player/Player.h"
#include "enemies/Enemy.h"

class BattleSystem {
public:
	bool handleFleeAttempt();
	bool handlePlayerTurn(Player& player, Enemy& enemy);
	void handleEnemyTurn(Player& player, Enemy& enemy);
	bool checkLifeStatus(Player& player, Enemy& enemy);
	void handleVictory(Player& player, Enemy& enemy);
	void handleDefeat(Player& player);
	void displayCombatStatus(Player& player, Enemy& enemy);
	void handleQuestProgress(Player& player, Enemy& enemy);
};