#include "Team.h"
#include <iostream>

Druzyna::Druzyna(const string n, int w, int p)
    : nazwa(n), wygrane(w), przegrane(p) {
}

string Druzyna::getNazwa_() {
    return nazwa;
}
string Druzyna::getNazwa() {
    string tmp = nazwa;
    for (char& znak : tmp) {
        if (znak == '_') {
            znak = ' ';
        }
    }
    return tmp;
}