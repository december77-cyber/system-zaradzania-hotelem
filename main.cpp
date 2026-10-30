#include <iostream>
#include "system_zarzadzania_hotelem.h"
#include "usluga_dodatkowa.h"

int main() {
    // Wymóg: Standard C++17 oraz czytelna demonstracja scenariuszy
    std::cout << "   DEMONSTRACJA USER STORIES - SYSTEM HOTELOWY    \n";

    // Utworzenie głównego obiektu zarządzającego systemem
    SystemZarzadzaniaHotelem hotel;

    // --- SCENARIUSZ 1: Dodanie nowego pokoju (Zarządcza / Administracyjna) ---
    std::cout << "[1] Dodawanie nowego pokoju do katalogu:\n";
    hotel.dodaj_pokoj(101, 2);
    hotel.dodaj_pokoj(102, 3);
    std::cout << "\n";

    // --- SCENARIUSZ 2: Sprawdzanie dostępności pokoi (Wyszukiwanie / Przeglądanie) ---
    std::cout << "[2] Wyszukiwanie wolnych pokoi w wybranym terminie:\n";
    hotel.sprawdz_dostepnosc("2026-07-01", "2026-07-05");
    std::cout << "\n";

    // --- SCENARIUSZ 3: Złożenie rezerwacji (Tworzenie / Transakcja) ---
    std::cout << "[3] Składanie rezerwacji pokoju przez gościa:\n";
    hotel.zarezerwuj(1, 101);
    std::cout << "\n";

    // --- SCENARIUSZ 4: Anulowanie rezerwacji i opłata manipulacyjna (Logika biznesowa) ---
    std::cout << "[4] Anulowanie rezerwacji oraz ewentualne naliczenie opłaty:\n";
    hotel.anuluj_rezerwacje(1);
    hotel.nalicz_oplate_manipulacyjna(1, 10, 50.0f);
    std::cout << "\n";

    // --- SCENARIUSZ 5: Zameldowanie gościa (Zarządcza / Administracyjna) ---
    // (Tworzymy nową rezerwację do celów demonstracji zameldowania i wymeldowania)
    hotel.zarezerwuj(2, 102);
    std::cout << "\n[5] Zameldowanie gościa na podstawie numeru rezerwacji:\n";
    hotel.zamelduj(2);
    std::cout << "\n";

    // --- SCENARIUSZ 6: Wymeldowanie gościa i faktura końcowa (Logika biznesowa) ---
    std::cout << "[6] Wymeldowanie gościa i generowanie faktury końcowej:\n";
    hotel.wymelduj(2);
    std::cout << "\n";

    std::cout << "   WSZYSTKIE SCENARIUSZE ZOSTALY ZDEMONSTROWANE   \n";

    return 0;
}