#include <iostream>
#include "system_zarzadzania_hotelem.h"
#include "usluga_dodatkowa.h"

int main() {
    std::cout << "====================================================\n";
    std::cout << "   DEMONSTRACJA USER STORIES - SYSTEM HOTELOWY      \n";
    std::cout << "====================================================\n\n";

    SystemZarzadzaniaHotelem hotel;

    std::cout << "[0] Weryfikacja uzytkownikow systemu (Polimorfizm):\n";
    hotel.wyswietlUzytkownikowPolimorficznie();
    std::cout << "\n";

    std::cout << "[1] Dodawanie nowych pokoi do katalogu:\n";
    hotel.dodaj_pokoj(101, 2);
    hotel.dodaj_pokoj(102, 3);
    std::cout << "\n";

    std::cout << "[2] Wyszukiwanie wolnych pokoi w wybranym terminie:\n";
    hotel.sprawdz_dostepnosc("2026-07-01", "2026-07-05");
    std::cout << "\n";

    std::cout << "[3] Skladanie rezerwacji pokoju przez goscia:\n";
    hotel.zarezerwuj(1, 101, "2026-07-01", "2026-07-05");
    std::cout << "  -> Weryfikacja dostepnosci po zlozeniu rezerwacji:\n";
    hotel.sprawdz_dostepnosc("2026-07-01", "2026-07-05");
    std::cout << "\n";

    std::cout << "[4] Anulowanie rezerwacji oraz oplata manipulacyjna:\n";
    hotel.anuluj_rezerwacje(1);
    hotel.nalicz_oplate_manipulacyjna(1, 10, 50.0f);
    std::cout << "\n";

    std::cout << "[5] Rezerwacja, zameldowanie i zamowienie uslug:\n";
    hotel.zarezerwuj(2, 102, "2026-07-10", "2026-07-14");
    hotel.zamelduj(2);
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Sniadanie kontynentalne", 45.0f));
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Dostep do strefy SPA", 120.0f));
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Parking strzezony", 30.0f));
    std::cout << "\n";

    std::cout << "[6] Wymeldowanie goscia i rozliczenie (<<include>>):\n";
    hotel.wymelduj(2, "PL5252525252");
    std::cout << "\n";

    std::cout << "====================================================\n";
    std::cout << "   WSZYSTKIE SCENARIUSZE ZOSTALY ZDEMONSTROWANE     \n";
    std::cout << "====================================================\n";

    return 0;
}
