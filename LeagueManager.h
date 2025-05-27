#pragma once
#include <vector>
#include "Team.h"

extern std::vector<Team> teams;

void addTeam();
void addPlayer();
void playMatch();
void showStats();
void saveStatsToFile();
void importStatsFromFile();
void menu();
