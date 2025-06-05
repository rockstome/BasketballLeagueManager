#include "Player.h"
#include <iostream>

Zawodnik::Zawodnik(const string i, const string n, int w, Druzyna* d)
    : imie(i), nazwisko(n), wiek(w), druzyna(d) {}

void Zawodnik::wypisz() {
    cout << "Imie: " << imie
        << ", Nazwisko: " << nazwisko
        << ", Wiek: " << wiek
        << ", Drużyna: " << druzyna->getNazwa() << endl;
}
string Zawodnik::getImie() {
    return imie;
}
string Zawodnik::getNazwisko() {
    return nazwisko;
}
int Zawodnik::getWiek() {
    return wiek;
}
Druzyna* Zawodnik::getDruzyna() {
    return druzyna;
}
void Zawodnik::edytujImie(Zawodnik& z, string nowaWart) {
    z.imie = nowaWart;
}
void Zawodnik::edytujNazwisko(Zawodnik& z, string nowaWart) {
    z.nazwisko = nowaWart;
}
void Zawodnik::edytujWiek(Zawodnik& z, int nowaWart) {
    z.wiek = nowaWart;
}
void Zawodnik::edytujDruzyne(Zawodnik& z, Druzyna* nowaWart) {
    z.druzyna = nowaWart;
}