#pragma once
#include <string>

using namespace std;

class Druzyna {
	string nazwa;
	int wygrane = 0;
	int przegrane = 0;

public:
	Druzyna(const string n, int w, int p);
	string getNazwa();
	string getNazwa_();
	void dodajWygrana();
	void dodajPrzegrana();
	int pobierzWygrane();
	int pobierzPrzegrane();
};
