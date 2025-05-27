# Basketball League Manager

Konsolowa aplikacja do zarządzania ligą koszykówki. Pozwala na:

- Dodawanie drużyn i zawodników
- Rozgrywanie meczów między drużynami
- Wyświetlanie statystyk drużyn i zawodników
- Zapisywanie oraz importowanie statystyk z pliku tekstowego

## Jak uruchomić

1. Skompiluj projekt w Visual Studio 2022 (C++14).
2. Uruchom program.
3. Korzystaj z menu, aby zarządzać ligą.

## Struktura projektu

- `Player.h` – definicja klasy zawodnika
- `Team.h` – definicja klasy drużyny
- `LeagueManager.h` – deklaracje funkcji zarządzających ligą
- `LeagueManager.cpp` – implementacje funkcji zarządzających ligą
- `main.cpp` – punkt wejścia programu

## Funkcje programu

- Dodawanie drużyn i zawodników
- Rozgrywanie meczów i aktualizacja statystyk
- Wyświetlanie statystyk w konsoli
- Zapisywanie i wczytywanie statystyk z pliku `league_stats.txt`

## TODO – propozycje rozwoju

- [ ] Możliwość usuwania drużyn i zawodników
- [ ] Edycja danych drużyn i zawodników (np. zmiana nazwy)
- [ ] Dodawanie punktów zawodnikom bezpośrednio podczas meczu (aktualnie punkty są tylko dla drużyny)
- [ ] Obsługa różnych sezonów i archiwizacja wyników
- [ ] Prosta walidacja danych wejściowych (np. unikalność nazw zespołów i zawodników)
- [ ] Obsługa rankingów i tabeli ligowej
- [ ] Możliwość zapisywania/wczytywania wielu lig
- [ ] Testy jednostkowe dla kluczowych funkcji

---

Projekt edukacyjny – możesz dowolnie rozwijać i modyfikować!
