#pragma once
#include "Team.h"
#include <string>

using namespace std;

class Zawodnik {
	Druzyna* druzyna;
	string imie, nazwisko;
	int wiek;

public:
	Zawodnik(const string i, const string n, int w, Druzyna* d);
	string getImie();
	string getNazwisko();
	int getWiek();
	Druzyna* getDruzyna();
	virtual void wypisz();
	void edytujImie(Zawodnik& z, string nowaWart);
	void edytujNazwisko(Zawodnik& z, string nowaWart);
	void edytujWiek(Zawodnik& z, int nowaWart);
	void edytujDruzyne(Zawodnik& z, Druzyna* nowaWart);
};

class ZawodnikAmator : public Zawodnik {
public:
	ZawodnikAmator(const string i, const string n, int w, Druzyna* d);
	virtual void wypisz() override;
};

class ZawodnikZawodowy : public Zawodnik {
public:
	ZawodnikZawodowy(const string i, const string n, int w, Druzyna* d);
	virtual void wypisz() override;
};
