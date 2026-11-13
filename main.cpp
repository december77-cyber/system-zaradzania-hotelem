#include <iostream>
#include <limits>
#include <string>
#include "system_zarzadzania_hotelem.h"
#include "usluga_dodatkowa.h"

void wyczyscBuforWejscia() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int wczytajLiczbeCalkowita(const std::string& komunikat) {
    int wartosc = 0;
    while (true) {
        std::cout << komunikat;
        if (std::cin >> wartosc) {
            wyczyscBuforWejscia();
            return wartosc;
        }
        std::cout << "  [Blad] Wprowadz poprawna liczbe calkowita.\n";
        wyczyscBuforWejscia();
    }
}

float wczytajKwote(const std::string& komunikat) {
    float wartosc = 0.0f;
    while (true) {
        std::cout << komunikat;
        if (std::cin >> wartosc) {
            wyczyscBuforWejscia();
            return wartosc;
        }
        std::cout << "  [Blad] Wprowadz poprawna liczbe.\n";
        wyczyscBuforWejscia();
    }
}

bool czyRokPrzestepny(int rok) {
    return (rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0);
}

bool czyPoprawnaData(const std::string& data) {
    if (data.size() != 10 || data[4] != '-' || data[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (data[static_cast<size_t>(i)] < '0' ||
            data[static_cast<size_t>(i)] > '9') {
            return false;
        }
    }

    int rok = std::stoi(data.substr(0, 4));
    int miesiac = std::stoi(data.substr(5, 2));
    int dzien = std::stoi(data.substr(8, 2));

    if (rok < 1900 || miesiac < 1 || miesiac > 12 || dzien < 1) {
        return false;
    }

    const int DNI_W_MIESIACU[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int max_dni = DNI_W_MIESIACU[miesiac - 1];
    if (miesiac == 2 && czyRokPrzestepny(rok)) {
        max_dni = 29;
    }

    return dzien <= max_dni;
}

void wczytajZakresDat(std::string& data_od, std::string& data_do) {
    while (true) {
        std::cout << "Data poczatku (RRRR-MM-DD): ";
        std::getline(std::cin, data_od);
        std::cout << "Data konca (RRRR-MM-DD): ";
        std::getline(std::cin, data_do);

        if (!czyPoprawnaData(data_od) || !czyPoprawnaData(data_do)) {
            std::cout << "  [Blad] Niepoprawna data lub format. "
                      << "Uzyj poprawnej daty RRRR-MM-DD (np. 2026-08-01).\n";
            continue;
        }
        if (data_od >= data_do) {
            std::cout << "  [Blad] Data poczatku musi byc wczesniejsza "
                      << "niz data konca! Sprobuj ponownie.\n";
            continue;
        }
        break;
    }
}

void uruchomScenariuszDemo(SystemZarzadzaniaHotelem& hotel) {
    std::cout << "\n====================================================\n";
    std::cout << "   AUTOMATYCZNA DEMONSTRACJA USER STORIES           \n";
    std::cout << "====================================================\n\n";

    std::cout << "[0] Weryfikacja uzytkownikow (Polimorfizm):\n";
    hotel.wyswietlUzytkownikowPolimorficznie();

    std::cout << "\n[1] Dodawanie nowych pokoi do katalogu:\n";
    hotel.dodaj_pokoj(101, 2);
    hotel.dodaj_pokoj(102, 3);

    std::cout << "\n[2] Sprawdzanie dostepnosci pokoi:\n";
    hotel.sprawdz_dostepnosc("2026-07-01", "2026-07-05");

    std::cout << "\n[3] Skladanie rezerwacji pokoju przez goscia:\n";
    hotel.zarezerwuj(1, 101, "2026-07-01", "2026-07-05");
    hotel.sprawdz_dostepnosc("2026-07-01", "2026-07-05");

    std::cout << "\n[4] Anulowanie rezerwacji oraz oplata manipulacyjna:\n";
    hotel.anuluj_rezerwacje(1);
    hotel.nalicz_oplate_manipulacyjna(1, 10, 50.0f);

    std::cout << "\n[5] Rezerwacja, zameldowanie i zamowienie uslug:\n";
    hotel.zarezerwuj(2, 102, "2026-07-10", "2026-07-14");
    hotel.zamelduj(2);
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Sniadanie kontynentalne", 45.0f));
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Dostep do strefy SPA", 120.0f));
    hotel.dodajUslugeDoRezerwacji(
        2, UslugaDodatkowa("Parking strzezony", 30.0f));

    std::cout << "\n[6] Wymeldowanie i rozliczenie (<<include>>):\n";
    hotel.wymelduj(2, "PL5252525252");

    std::cout << "\n====================================================\n";
    std::cout << "   KONIEC DEMONSTRACJI USER STORIES                  \n";
    std::cout << "====================================================\n";
}

void wyswietlMenu() {
    std::cout << "\n========================================\n"
              << "      SYSTEM ZARZADZANIA HOTELEM        \n"
              << "========================================\n"
              << "1. Wyswietl uzytkownikow systemu (Osoba)\n"
              << "2. Dodaj nowy pokoj do katalogu\n"
              << "3. Sprawdz dostepnosc pokoi\n"
              << "4. Utworz rezerwacje pokoju\n"
              << "5. Dodaj usluge dodatkowa do rezerwacji\n"
              << "6. Zamelduj goscia\n"
              << "7. Wymelduj goscia i wystaw fakture\n"
              << "8. Anuluj rezerwacje\n"
              << "9. Nalicz oplate manipulacyjna\n"
              << "10. Automatyczna demonstracja User Stories\n"
              << "0. Wyjscie\n";
}

int main() {
    SystemZarzadzaniaHotelem hotel;
    hotel.dodaj_pokoj(101, 2);
    hotel.dodaj_pokoj(102, 3);
    hotel.dodaj_pokoj(201, 4);

    while (true) {
        wyswietlMenu();
        int opcja = wczytajLiczbeCalkowita("Wybierz opcje: ");

        if (opcja == 0) {
            std::cout << "Zamykanie systemu...\n";
            break;
        }

        switch (opcja) {
            case 1: {
                std::cout << "\n--- UZYTKOWNICY SYSTEMU ---\n";
                hotel.wyswietlUzytkownikowPolimorficznie();
                break;
            }
            case 2: {
                std::cout << "\n--- DODAWANIE NOWEGO POKOJU ---\n";
                int nr_pokoju = wczytajLiczbeCalkowita("Numer pokoju: ");
                int liczba_lozek = wczytajLiczbeCalkowita("Liczba lozek: ");
                hotel.dodaj_pokoj(nr_pokoju, liczba_lozek);
                break;
            }
            case 3: {
                std::string data_od = "";
                std::string data_do = "";
                std::cout << "\n--- SPRAWDZANIE DOSTEPNOSCI ---\n";
                wczytajZakresDat(data_od, data_do);
                hotel.sprawdz_dostepnosc(data_od, data_do);
                break;
            }
            case 4: {
                std::string data_od = "";
                std::string data_do = "";
                std::cout << "\n--- NOWA REZERWACJA ---\n";
                int id_goscia = wczytajLiczbeCalkowita(
                    "ID goscia (domyslnie 1 lub 2): ");
                int nr_pokoju = wczytajLiczbeCalkowita("Numer pokoju: ");
                wczytajZakresDat(data_od, data_do);
                hotel.zarezerwuj(id_goscia, nr_pokoju, data_od, data_do);
                break;
            }
            case 5: {
                std::string nazwa_uslugi = "";
                std::cout << "\n--- DODAWANIE USLUGI DODATKOWEJ ---\n";
                int id_rezerwacji = wczytajLiczbeCalkowita("ID rezerwacji: ");
                std::cout << "Nazwa uslugi (np. SPA, Sniadanie): ";
                std::getline(std::cin, nazwa_uslugi);
                float cena = wczytajKwote("Cena uslugi (PLN): ");
                hotel.dodajUslugeDoRezerwacji(
                    id_rezerwacji, UslugaDodatkowa(nazwa_uslugi, cena));
                break;
            }
            case 6: {
                std::cout << "\n--- ZAMELDOWANIE GOSCIA ---\n";
                int id_rezerwacji = wczytajLiczbeCalkowita("ID rezerwacji: ");
                hotel.zamelduj(id_rezerwacji);
                break;
            }
            case 7: {
                std::string nip = "";
                std::cout << "\n--- WYMELDOWANIE I FAKTURA ---\n";
                int id_rezerwacji = wczytajLiczbeCalkowita("ID rezerwacji: ");
                std::cout << "NIP klienta (np. PL5252525252): ";
                std::getline(std::cin, nip);
                hotel.wymelduj(id_rezerwacji, nip);
                break;
            }
            case 8: {
                std::cout << "\n--- ANULOWANIE REZERWACJI ---\n";
                int id_rezerwacji = wczytajLiczbeCalkowita("ID rezerwacji: ");
                hotel.anuluj_rezerwacje(id_rezerwacji);
                break;
            }
            case 9: {
                std::cout << "\n--- OPLATA MANIPULACYJNA ---\n";
                int id_goscia = wczytajLiczbeCalkowita(
                    "ID goscia (domyslnie 1 lub 2): ");
                int id_recepcjonisty = wczytajLiczbeCalkowita(
                    "ID recepcjonisty (domyslnie 10): ");
                float kwota = wczytajKwote("Kwota oplaty (PLN): ");
                hotel.nalicz_oplate_manipulacyjna(
                    id_goscia, id_recepcjonisty, kwota);
                break;
            }
            case 10: {
                uruchomScenariuszDemo(hotel);
                break;
            }
            default: {
                std::cout << "Nieznana opcja. Wybierz numer z menu.\n";
                break;
            }
        }
    }

    return 0;
}
