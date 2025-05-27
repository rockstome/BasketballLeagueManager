#include "LeagueManager.h"
#include <iostream>
#include <fstream>
#include <limits>

std::vector<Team> teams;

void addTeam() {
	Team team;
	std::cout << "Enter team name: ";
	std::getline(std::cin, team.name);
	teams.push_back(team);
	std::cout << "Team added.\n";
}

void addPlayer() {
	if (teams.empty()) {
		std::cout << "No teams available. Add a team first.\n";
		return;
	}
	std::cout << "Select team number:\n";
	for (size_t i = 0; i < teams.size(); ++i)
		std::cout << i + 1 << ". " << teams[i].name << "\n";
	size_t idx;
	std::cin >> idx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (idx < 1 || idx > teams.size()) {
		std::cout << "Invalid team number.\n";
		return;
	}
	Player player;
	std::cout << "Enter player name: ";
	std::getline(std::cin, player.name);
	player.points = 0;
	teams[idx - 1].players.push_back(player);
	std::cout << "Player added.\n";
}

void playMatch() {
	if (teams.size() < 2) {
		std::cout << "Not enough teams to play a match.\n";
		return;
	}
	std::cout << "Select first team number:\n";
	for (size_t i = 0; i < teams.size(); ++i)
		std::cout << i + 1 << ". " << teams[i].name << "\n";
	size_t idx1, idx2;
	std::cin >> idx1;
	std::cout << "Select second team number:\n";
	std::cin >> idx2;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (idx1 < 1 || idx1 > teams.size() || idx2 < 1 || idx2 > teams.size() || idx1 == idx2) {
		std::cout << "Invalid team selection.\n";
		return;
	}
	int score1, score2;
	std::cout << "Enter score for " << teams[idx1 - 1].name << ": ";
	std::cin >> score1;
	std::cout << "Enter score for " << teams[idx2 - 1].name << ": ";
	std::cin >> score2;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	teams[idx1 - 1].gamesPlayed++;
	teams[idx2 - 1].gamesPlayed++;
	if (score1 > score2) {
		teams[idx1 - 1].gamesWon++;
		teams[idx2 - 1].gamesLost++;
	}
	else if (score2 > score1) {
		teams[idx2 - 1].gamesWon++;
		teams[idx1 - 1].gamesLost++;
	}
	std::cout << "Match recorded.\n";
}

void showStats() {
	for (const auto& team : teams) {
		std::cout << "Team: " << team.name << "\n";
		std::cout << "Games Played: " << team.gamesPlayed
			<< ", Won: " << team.gamesWon
			<< ", Lost: " << team.gamesLost << "\n";
		std::cout << "Players:\n";
		for (const auto& player : team.players)
			std::cout << "  " << player.name << ", Points: " << player.points << "\n";
		std::cout << "----------------------\n";
	}
}

void saveStatsToFile() {
	std::ofstream file("league_stats.txt");
	for (const auto& team : teams) {
		file << "Team: " << team.name << "\n";
		file << "Games Played: " << team.gamesPlayed
			<< ", Won: " << team.gamesWon
			<< ", Lost: " << team.gamesLost << "\n";
		file << "Players:\n";
		for (const auto& player : team.players)
			file << "  " << player.name << ", Points: " << player.points << "\n";
		file << "----------------------\n";
	}
	file.close();
	std::cout << "Stats saved to league_stats.txt\n";
}

void importStatsFromFile() {
	std::ifstream file("league_stats.txt");
	if (!file) {
		std::cout << "Could not open league_stats.txt for reading.\n";
		return;
	}
	teams.clear();
	std::string line;
	Team currentTeam;
	while (std::getline(file, line)) {
		if (line.find("Team: ") == 0) {
			if (!currentTeam.name.empty()) {
				teams.push_back(currentTeam);
				currentTeam = Team();
			}
			currentTeam.name = line.substr(6);
		}
		else if (line.find("Games Played: ") == 0) {
			int played = 0, won = 0, lost = 0;
			sscanf_s(line.c_str(), "Games Played: %d, Won: %d, Lost: %d", &played, &won, &lost);
			currentTeam.gamesPlayed = played;
			currentTeam.gamesWon = won;
			currentTeam.gamesLost = lost;
		}
		else if (line.find("  ") == 0) {
			Player player;
			size_t commaPos = line.find(", Points: ");
			if (commaPos != std::string::npos) {
				player.name = line.substr(2, commaPos - 2);
				player.points = std::stoi(line.substr(commaPos + 10));
				currentTeam.players.push_back(player);
			}
		}
		else if (line.find("----------------------") == 0) {
			if (!currentTeam.name.empty()) {
				teams.push_back(currentTeam);
				currentTeam = Team();
			}
		}
	}
	// Add last team if file doesn't end with separator
	if (!currentTeam.name.empty()) {
		teams.push_back(currentTeam);
	}
	file.close();
	std::cout << "Stats imported from league_stats.txt\n";
}

void menu() {
	while (true) {
		std::cout << "\nBasketball League Manager\n";
		std::cout << "1. Add Team\n";
		std::cout << "2. Add Player\n";
		std::cout << "3. Play Match\n";
		std::cout << "4. Show Stats\n";
		std::cout << "5. Save Stats to File\n";
		std::cout << "6. Import Stats from File\n";
		std::cout << "0. Exit\n";
		std::cout << "Choose option: ";
		int choice;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice) {
		case 1: addTeam(); break;
		case 2: addPlayer(); break;
		case 3: playMatch(); break;
		case 4: showStats(); break;
		case 5: saveStatsToFile(); break;
		case 6: importStatsFromFile(); break;
		case 0: return;
		default: std::cout << "Invalid option.\n";
		}
	}
}