#include "LeagueManager.h"
#include "Player.h"
#include "Team.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<Zawodnik*> zawodnicy;
vector<Druzyna> druzyny;

void wczytanieDruzyn() {
	ifstream plik("druzyny.txt");

	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku!" << endl;
		return;
	}

	string nazwa;
	int wygrane, przegrane;

	// wczytanie danych do obiektów
	while (plik >> nazwa >> wygrane >> przegrane) {
		druzyny.emplace_back(nazwa, wygrane, przegrane);
	}
	plik.close();
}

void wczytanieZawodnikow() {
	ifstream plik("zawodnicy.txt");

	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku!" << endl;
		return;
	}

	Druzyna* wsk_druzyna{};
	string typ, imie, nazwisko, nazwa_druzyny;
	int wiek;

	// wczytanie danych do obiektów
	while (plik >> typ >> imie >> nazwisko >> wiek >> nazwa_druzyny) {
		for (int i = 0; i < size(druzyny); i++) {
			if (nazwa_druzyny == druzyny[i].getNazwa_()) {
				wsk_druzyna = &druzyny[i];
				break;
			}
		}
		if (typ == "A") {
			zawodnicy.push_back(new ZawodnikAmator(imie, nazwisko, wiek, wsk_druzyna));
		}
		else if (typ == "Z") {
			zawodnicy.push_back(new ZawodnikZawodowy(imie, nazwisko, wiek, wsk_druzyna));
		}
	}

	plik.close();
}

void dodajDruzyne() {
	string n;
	cout << "\nDODAWANIE DRUŻYNY\n";
	cout << "Podaj nazwę druzyny: ";
	cin.ignore();
	getline(cin, n);
	for (char& znak : n) {
		if (znak == ' ') {
			znak = '_';
		}
	}
	ofstream plik("druzyny.txt", ios::app); // ios::app = dopisywanie na końcu pliku
	if (plik.is_open()) {
		druzyny.emplace_back(n, 0, 0);
		plik << n << " 0 " << '0' << '\n';
		cout << "Dodano drużynę" << endl;
		plik.close();
	}
	else {
		cerr << "Nie mozna otworzyc pliku do dopisania " << endl;
	}
}

int wyborZawodnika() {
	// zwraca indeks zawodnika
	int n;
	for (int i = 0; i < size(zawodnicy); i++) {
		cout << i + 1 << ' ';
		zawodnicy[i]->wypisz();
	}
	cout << "\nWybierz zawodnika: ";
	cin >> n;
	if (n < 1 || n > size(zawodnicy)) {
		cout << "Zawodnik z podanym numerem nie istnieje\n";
		menu();
	}
	return n - 1;
}

void dodajZawodnika() {
	Druzyna* wsk_druzyna;
	string imie, nazwisko;
	int wiek, nr_druzyny;
	cout << "\nDODAWANIE ZAWODNIKA\n";
	cout << "Podaj imię: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj wiek: ";
	cin >> wiek;
	cout << "Wybierz drużynę:" << endl;
	for (int i = 0; i < size(druzyny); i++) {
		cout << i + 1 << " " << druzyny[i].getNazwa() << endl;
	}
	cin >> nr_druzyny;
	if (nr_druzyny < 1 || nr_druzyny > size(druzyny)) {
		cout << "Nie ma drużny z takim numerem\n";
		return;
	}
	wsk_druzyna = &druzyny[nr_druzyny - 1];

	cout << "Podaj typ zawodnika (1 - Amator, 2 - Zawodowy): ";
	int typ;
	cin >> typ;

	if (typ == 1) {
		zawodnicy.push_back(new ZawodnikAmator(imie, nazwisko, wiek, wsk_druzyna));
	}
	else if (typ == 2) {
		double pensja;
		cout << "Podaj pensję zawodnika: ";
		cin >> pensja;
		zawodnicy.push_back(new ZawodnikZawodowy(imie, nazwisko, wiek, wsk_druzyna));
	}
	else {
		cout << "Nieznany typ zawodnika.\n";
		return;
	}

	ofstream plik("zawodnicy.txt", ios::app); // ios::app = dopisywanie na końcu pliku
	if (plik.is_open()) {
		if (typ == 1) {
			plik << "A " << imie << " " << nazwisko << " " << wiek << " " << wsk_druzyna->getNazwa_() << '\n';
		}
		else {
			plik << "Z " << imie << " " << nazwisko << " " << wiek << " " << wsk_druzyna->getNazwa_() << '\n';
		}
		cout << "Dodano zawodnika" << endl;
		plik.close();
	}
	else {
		cerr << "Nie mozna otworzyc pliku do dopisania " << endl;
	}
}

void usunZawodnika() {
	cout << "\nUSUWANIE ZAWODNIKA\n";
	int n = wyborZawodnika();
	ifstream plik("zawodnicy.txt");
	vector<string> noweLinie;
	string linia;

	while (getline(plik, linia)) {
		// Sprawdzenie, czy linia pasuje do zawodnika
		if (linia.find(zawodnicy[n]->getImie() + " " + zawodnicy[n]->getNazwisko() + " ") == string::npos) {
			noweLinie.push_back(linia); // dodaj tylko jeśli nie pasuje
		}
	}
	plik.close();

	// Nadpisanie pliku nową zawartością
	ofstream plikWy("zawodnicy.txt", ios::trunc);
	for (const string& l : noweLinie) {
		plikWy << l << '\n';
	}
	plikWy.close();
	zawodnicy.erase(zawodnicy.begin() + n);
	cout << "Usunięto zawodnika\n";
}

void edytujZawodnika() {
	int n, n2;
	cout << "\nEDYCJA ZAWODNIKA\n";
	n = wyborZawodnika();
	cout << "1 Imie \n2 Nazwisko \n3 Wiek \n4 Drużyna\n";
	cout << "Nr do edycji: ";
	cin >> n2;
	if (n2 == 1) {
		string imie;
		cout << "Podaj nową wartość: ";
		cin >> imie;
		zawodnicy[n]->edytujImie(*zawodnicy[n], imie);
	}
	else if (n2 == 2) {
		string nazwisko;
		cout << "Podaj nową wartość: ";
		cin >> nazwisko;
		zawodnicy[n]->edytujNazwisko(*zawodnicy[n], nazwisko);
	}
	else if (n2 == 3) {
		int wiek;
		cout << "Podaj nową wartość: ";
		cin >> wiek;
		zawodnicy[n]->edytujWiek(*zawodnicy[n], wiek);
	}
	else if (n2 == 4) {
		Druzyna* wsk_druzyna;
		int nr_druzyny;
		cout << "\nWybierz nową drużynę:" << endl;
		for (int i = 0; i < size(druzyny); i++) {
			cout << i + 1 << " " << druzyny[i].getNazwa() << endl;
		}
		cin >> nr_druzyny;
		wsk_druzyna = &druzyny[nr_druzyny - 1];
		zawodnicy[n]->edytujDruzyne(*zawodnicy[n], wsk_druzyna);
	}
	else {
		cout << "Podano zły numer\n";
	}
	//export zmienionych danych do pliku
	ofstream plik("zawodnicy.txt");
	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku" << endl;
		return;
	}
	for (int i = 0; i < size(zawodnicy); i++) {
		if (dynamic_cast<ZawodnikAmator*>(zawodnicy[i])) {
			plik << "A " << zawodnicy[i]->getImie() << " " << zawodnicy[i]->getNazwisko()
				<< " " << zawodnicy[i]->getWiek() << " " << zawodnicy[i]->getDruzyna()->getNazwa_() << '\n';
		}
		else if (auto zawodowy = dynamic_cast<ZawodnikZawodowy*>(zawodnicy[i])) {
			plik << "Z " << zawodnicy[i]->getImie() << " " << zawodnicy[i]->getNazwisko()
				<< " " << zawodnicy[i]->getWiek() << " " << zawodnicy[i]->getDruzyna()->getNazwa_() << '\n';
		}
	}
	plik.close();
}

void pokazStatystyki() {
	cout << "\nSTATYSTYKI (wygrane:przegrane)\n";
	ifstream plik("druzyny.txt");
	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku!" << endl;
		return;
	}
	string nazwa;
	int wygrane, przegrane;

	while (plik >> nazwa >> wygrane >> przegrane) {
		cout << nazwa << " " << wygrane << ":" << przegrane << endl;
	}
	plik.close();
}

void zagrajMecz() {
	if (druzyny.size() < 2) {
		cout << "Musi być co najmniej 2 drużyny, aby rozegrać mecz.\n";
		return;
	}

	cout << "\nWYBÓR DRUŻYN DO MECZU\n";
	for (size_t i = 0; i < druzyny.size(); ++i) {
		cout << i + 1 << ". " << druzyny[i].getNazwa() << endl;
	}

	int idx1, idx2;
	cout << "Wybierz numer pierwszej drużyny: ";
	cin >> idx1;
	cout << "Wybierz numer drugiej drużyny: ";
	cin >> idx2;

	if (idx1 < 1 || idx1 > druzyny.size() || idx2 < 1 || idx2 > druzyny.size() || idx1 == idx2) {
		cout << "Nieprawidłowy wybór drużyn.\n";
		return;
	}

	Druzyna& druzyna1 = druzyny[idx1 - 1];
	Druzyna& druzyna2 = druzyny[idx2 - 1];

	cout << "Podaj liczbę punktów dla " << druzyna1.getNazwa() << ": ";
	int punkty1;
	cin >> punkty1;

	cout << "Podaj liczbę punktów dla " << druzyna2.getNazwa() << ": ";
	int punkty2;
	cin >> punkty2;

	if (punkty1 == punkty2) {
		cout << "Remis nie jest możliwy w meczu. Podaj poprawne wyniki.\n";
		return;
	}

	// Aktualizacja statystyk w pamięci
	if (punkty1 > punkty2) {
		druzyna1.dodajWygrana();
		druzyna2.dodajPrzegrana();
		cout << "Wygrała drużyna: " << druzyna1.getNazwa() << endl;
	}
	else {
		druzyna2.dodajWygrana();
		druzyna1.dodajPrzegrana();
		cout << "Wygrała drużyna: " << druzyna2.getNazwa() << endl;
	}

	// Zapisz zaktualizowane statystyki do pliku
	ofstream plik("druzyny.txt", ios::trunc);
	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku do zapisu wyników!\n";
		return;
	}
	for (Druzyna& d : druzyny) {
		plik << d.getNazwa_() << " " << d.pobierzWygrane() << " " << d.pobierzPrzegrane() << '\n';
	}
	plik.close();
}

void menu() {
	while (true) {
		cout << "\nPolska Liga Koszykówki\n";
		cout << "1. Zagraj mecz\n";
		cout << "2. Pokaż statystyki drużyn\n";
		cout << "3. Dodaj drużyne\n";
		cout << "4. Dodaj zawodnika\n";
		cout << "5. Usuń zawodnika\n";
		cout << "6. Edytuj dane zawodnika\n";
		cout << "0. Wyjście\n";
		cout << "Wybierz opcję: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: zagrajMecz(); break;
		case 2: pokazStatystyki(); break;
		case 3: dodajDruzyne(); break;
		case 4: dodajZawodnika(); break;
		case 5: usunZawodnika(); break;
		case 6: edytujZawodnika(); break;
		case 0: return;
		default: cout << "Wybór spoza zakresu\n";
		}
	}
}