#include <locale.h>
#include "LeagueManager.h"

int main() {
	setlocale(LC_CTYPE, "Polish");

	wczytanieDruzyn();
	wczytanieZawodnikow();
	menu();
	return 0;
}