#pragma once
#include <string>
#include <vector>
#include "Player.h"

class Team {
public:
	std::string name;
	std::vector<Player> players;
	int gamesPlayed = 0;
	int gamesWon = 0;
	int gamesLost = 0;
};
