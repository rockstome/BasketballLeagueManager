# Dokumentacja projektu: Polska Liga Koszykówki

## Autorzy

- Piotr Duszyński
- Tomasz Solarz

## Opis zrealizowanego projektu

Projekt „Polska Liga Koszykówki” to konsolowa aplikacja w języku C++, umożliwiająca zarządzanie drużynami i zawodnikami w fikcyjnej lidze koszykarskiej. Program pozwala na dodawanie, edytowanie oraz usuwanie zawodników i drużyn, rozgrywanie meczów pomiędzy drużynami oraz prezentowanie statystyk wygranych i przegranych. Dane przechowywane są w plikach tekstowych, co umożliwia ich trwałość pomiędzy uruchomieniami programu. Projekt wykorzystuje mechanizmy programowania obiektowego, takie jak dziedziczenie i polimorfizm. W systemie wyróżniono dwa typy zawodników: amatorów i zawodowców, które dziedziczą po wspólnej klasie bazowej. Dzięki temu możliwe jest przechowywanie i obsługa różnych typów zawodników w jednej kolekcji oraz dynamiczne rozpoznawanie ich typu podczas działania programu.

## Instrukcja użytkownika

1. Uruchomienie programu
   Program uruchamia się w trybie konsolowym. Po uruchomieniu wyświetlane jest menu główne.
2. Menu główne
   • 1. Zagraj mecz – umożliwia rozegranie meczu pomiędzy wybranymi drużynami.
   • 2. Pokaż statystyki drużyn – wyświetla aktualne statystyki wszystkich drużyn.
   • 3. Dodaj drużynę – pozwala dodać nową drużynę do ligi.
   • 4. Dodaj zawodnika – umożliwia dodanie nowego zawodnika do wybranej drużyny.
   • 5. Usuń zawodnika – pozwala usunąć wybranego zawodnika z ligi.
   • 6. Edytuj dane zawodnika – umożliwia edycję danych wybranego zawodnika.
   • 0. Wyjście – kończy działanie programu.
3. Obsługa plików
   • Drużyny zapisywane są w pliku druzyny.txt.
   • Zawodnicy zapisywani są w pliku zawodnicy.txt.

## Ciekawostki związane z realizacją projektu

- Program automatycznie zamienia spacje w nazwach drużyn na podkreślenia, aby ułatwić obsługę plików tekstowych.
- Dane są przechowywane w prostych plikach tekstowych, co pozwala na łatwą edycję i przenoszenie danych między komputerami.
- W projekcie zastosowano dynamiczne struktury danych (std::vector), co umożliwia dowolne rozszerzanie liczby drużyn i zawodników bez ograniczeń.
- W projekcie zastosowano dziedziczenie i polimorfizm: klasy ZawodnikAmator i ZawodnikZawodowy dziedziczą po klasie bazowej Zawodnik, a ich obiekty są przechowywane jako wskaźniki w jednym kontenerze.
- Podczas zapisu i odczytu danych do/z pliku program rozpoznaje typ zawodnika (amator/zawodowy) i odpowiednio tworzy obiekty właściwej klasy.

## Podsumowanie i wnioski

Projekt spełnia założenia wstępne: umożliwia zarządzanie ligą koszykarską, rozgrywanie meczów oraz prezentację statystyk. Program jest prosty w obsłudze i pozwala na łatwe rozszerzanie bazy danych o nowe drużyny i zawodników. Zastosowanie plików tekstowych zapewnia trwałość danych, a interfejs konsolowy jest intuicyjny dla użytkownika.

## Możliwości rozbudowy projektu

- Dodanie obsługi rozgrywek ligowych (np. terminarz, tabele, play-offy).
- Wprowadzenie szczegółowych statystyk zawodników (punkty, asysty, zbiórki).
- Zaimplementowanie graficznego interfejsu użytkownika (GUI).
- Rozbudowa systemu autoryzacji użytkowników (np. role: administrator, trener).
- Wprowadzenie historii meczów i szczegółowych raportów pomeczowych.
