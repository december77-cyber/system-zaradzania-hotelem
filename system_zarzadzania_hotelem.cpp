#include "system_zarzadzania_hotelem.h"
#include <iomanip>
#include <iostream>

SystemZarzadzaniaHotelem::SystemZarzadzaniaHotelem()
    : nastepne_id_rezerwacji_(1) {
    lista_gosci_.emplace_back(1, "Jan", "Kowalski");
    lista_gosci_.emplace_back(2, "Anna", "Nowak");
    lista_recepcjonistow_.emplace_back(
        10, "Piotr", "Wisniewski", 10, "2024-03-01", 5200.0);
}

SystemZarzadzaniaHotelem::~SystemZarzadzaniaHotelem() = default;

Pokoj* SystemZarzadzaniaHotelem::znajdzPokoj(int nr_pokoju) {
    for (auto& pokoj : katalog_pokoi_) {
        if (pokoj.getNrPokoju() == nr_pokoju) {
            return &pokoj;
        }
    }
    return nullptr;
}

const Pokoj* SystemZarzadzaniaHotelem::znajdzPokoj(int nr_pokoju) const {
    for (const auto& pokoj : katalog_pokoi_) {
        if (pokoj.getNrPokoju() == nr_pokoju) {
            return &pokoj;
        }
    }
    return nullptr;
}

Rezerwacja* SystemZarzadzaniaHotelem::znajdzRezerwacje(int id_rezerwacji) {
    for (auto& rezerwacja : aktywne_rezerwacje_) {
        if (rezerwacja.getIdRezerwacji() == id_rezerwacji) {
            return &rezerwacja;
        }
    }
    return nullptr;
}

Gosc* SystemZarzadzaniaHotelem::znajdzGoscia(int id_goscia) {
    for (auto& gosc : lista_gosci_) {
        if (gosc.getId() == id_goscia) {
            return &gosc;
        }
    }
    return nullptr;
}

Recepcjonista* SystemZarzadzaniaHotelem::znajdzRecepcjoniste(
    int id_recepcjonisty) {
    for (auto& recepcjonista : lista_recepcjonistow_) {
        if (recepcjonista.getIdRecepcjonisty() == id_recepcjonisty) {
            return &recepcjonista;
        }
    }
    return nullptr;
}

void SystemZarzadzaniaHotelem::dodaj_pokoj(int id_pokoju, int liczba_lozek) {
    if (znajdzPokoj(id_pokoju) != nullptr) {
        std::cout << "  [Blad] Pokoj nr " << id_pokoju
                  << " juz istnieje w katalogu.\n";
        return;
    }

    const float STAWKA_BAZOWA = 100.0f;
    const float DOPLATA_ZA_LOZKO = 40.0f;
    float stawka = STAWKA_BAZOWA +
                   static_cast<float>(liczba_lozek) * DOPLATA_ZA_LOZKO;

    katalog_pokoi_.emplace_back(id_pokoju, liczba_lozek, stawka);
    std::cout << "  [OK] Dodano pokoj nr " << id_pokoju
              << " (lozka: " << liczba_lozek << ", stawka: "
              << std::fixed << std::setprecision(2) << stawka << " PLN/doba)\n";
}

std::vector<int> SystemZarzadzaniaHotelem::sprawdz_dostepnosc(
    const std::string& data_poczatku,
    const std::string& data_konca) const {
    std::vector<int> dostepne_pokoje;
    std::cout << "  Sprawdzanie dostepnosci w terminie " << data_poczatku
              << " -> " << data_konca << ":\n";

    for (const auto& pokoj : katalog_pokoi_) {
        bool dostepny = pokoj.czy_dostepny(data_poczatku, data_konca);
        std::cout << "    - Pokoj nr " << pokoj.getNrPokoju()
                  << " (" << pokoj.getIloscLozek() << "-osobowy, "
                  << pokoj.getStawkaZaDobe() << " PLN): "
                  << (dostepny ? "DOSTEPNY" : "ZAJETY") << "\n";
        if (dostepny) {
            dostepne_pokoje.push_back(pokoj.getNrPokoju());
        }
    }

    return dostepne_pokoje;
}

bool SystemZarzadzaniaHotelem::zarezerwuj(
    int id_goscia, int id_pokoju,
    const std::string& data_poczatku,
    const std::string& data_konca) {
    Gosc* gosc = znajdzGoscia(id_goscia);
    Pokoj* pokoj = znajdzPokoj(id_pokoju);

    if (gosc == nullptr || pokoj == nullptr) {
        std::cout << "  [Blad] Nieprawidlowe ID goscia lub numer pokoju.\n";
        return false;
    }

    if (!pokoj->czy_dostepny(data_poczatku, data_konca)) {
        std::cout << "  [Odmowa] Pokoj nr " << id_pokoju
                  << " jest niedostepny w terminie " << data_poczatku
                  << " - " << data_konca << ".\n";
        return false;
    }

    int id_nowej_rezerwacji = nastepne_id_rezerwacji_;
    ++nastepne_id_rezerwacji_;

    PozycjaRezerwacji pozycja(id_pokoju);
    Rezerwacja nowa_rezerwacja(id_nowej_rezerwacji, id_goscia,
                               data_poczatku, data_konca, pozycja);

    pokoj->zablokujTermin(data_poczatku, data_konca);
    aktywne_rezerwacje_.push_back(nowa_rezerwacja);
    gosc->dodajRezerwacje(nowa_rezerwacja);

    std::cout << "  [Potwierdzenie] Utworzono rezerwacje ID: "
              << id_nowej_rezerwacji << " dla goscia " << gosc->getImie()
              << " " << gosc->getNazwisko() << " (pokoj nr " << id_pokoju
              << ", termin: " << data_poczatku << " -> " << data_konca << ")\n";
    return true;
}

void SystemZarzadzaniaHotelem::anuluj_rezerwacje(int id_rezerwacji) {
    Rezerwacja* rezerwacja = znajdzRezerwacje(id_rezerwacji);
    if (rezerwacja == nullptr) {
        std::cout << "  [Blad] Nie znaleziono rezerwacji ID: "
                  << id_rezerwacji << "\n";
        return;
    }

    if (rezerwacja->getStanRezerwacji() == "anulowana") {
        std::cout << "  [Blad] Rezerwacja ID: " << id_rezerwacji
                  << " zostala juz wczesniej anulowana.\n";
        return;
    }

    if (rezerwacja->getStanRezerwacji() != "zlozona") {
        std::cout << "  [Blad] Nie mozna anulowac rezerwacji ID: "
                  << id_rezerwacji << " (aktualny stan: "
                  << rezerwacja->getStanRezerwacji() << ").\n";
        return;
    }

    Pokoj* pokoj = znajdzPokoj(rezerwacja->getNrPokoju());
    if (pokoj != nullptr) {
        pokoj->zwolnijTermin(rezerwacja->getDataPoczatku(),
                             rezerwacja->getDataKonca());
    }

    rezerwacja->zmienStan("anulowana");
    std::cout << "  [OK] Rezerwacja ID: " << id_rezerwacji
              << " zostala anulowana (zwolniono pokoj nr "
              << rezerwacja->getNrPokoju() << ").\n";
}

float SystemZarzadzaniaHotelem::nalicz_oplate_manipulacyjna(
    int id_goscia, int id_recepcjonisty, float kwota) {
    Gosc* gosc = znajdzGoscia(id_goscia);
    Recepcjonista* recepcjonista = znajdzRecepcjoniste(id_recepcjonisty);

    if (gosc == nullptr || recepcjonista == nullptr || kwota < 0.0f) {
        std::cout << "  [Blad] Nie mozna naliczyc oplaty manipulacyjnej.\n";
        return 0.0f;
    }

    std::cout << "  [Oplata] " << recepcjonista->pobierz_role() << " "
              << recepcjonista->getImie() << " "
              << recepcjonista->getNazwisko() << " naliczyl oplate "
              << std::fixed << std::setprecision(2) << kwota << " PLN dla: "
              << gosc->pobierz_role() << " " << gosc->getImie() << " "
              << gosc->getNazwisko() << ".\n";
    return kwota;
}

void SystemZarzadzaniaHotelem::zamelduj(int id_rezerwacji) {
    Rezerwacja* rezerwacja = znajdzRezerwacje(id_rezerwacji);
    if (rezerwacja == nullptr) {
        std::cout << "  [Blad] Rezerwacja ID: " << id_rezerwacji
                  << " nie istnieje.\n";
        return;
    }

    if (rezerwacja->getStanRezerwacji() != "zlozona") {
        std::cout << "  [Blad] Rezerwacja ID: " << id_rezerwacji
                  << " ma nieprawidlowy stan do meldunku ("
                  << rezerwacja->getStanRezerwacji() << ").\n";
        return;
    }

    rezerwacja->zmienStan("zameldowana");
    std::cout << "  [OK] Zameldowano goscia z rezerwacji ID: "
              << id_rezerwacji << " w pokoju nr "
              << rezerwacja->getNrPokoju() << ".\n";
}

void SystemZarzadzaniaHotelem::wymelduj(int id_rezerwacji,
                                        const std::string& nip) {
    Rezerwacja* rezerwacja = znajdzRezerwacje(id_rezerwacji);
    if (rezerwacja == nullptr) {
        std::cout << "  [Blad] Rezerwacja ID: " << id_rezerwacji
                  << " nie istnieje.\n";
        return;
    }

    if (rezerwacja->getStanRezerwacji() != "zameldowana") {
        std::cout << "  [Blad] Wymeldowanie mozliwe tylko dla zameldowanej "
                  << "rezerwacji (aktualny stan: "
                  << rezerwacja->getStanRezerwacji() << ").\n";
        return;
    }

    const Pokoj* pokoj = znajdzPokoj(rezerwacja->getNrPokoju());
    float stawka = (pokoj != nullptr) ? pokoj->getStawkaZaDobe() : 180.0f;

    rezerwacja->zmienStan("zakonczona");
    std::cout << "  [OK] Wymeldowano goscia z pokoju nr "
              << rezerwacja->getNrPokoju()
              << " (rezerwacja ID: " << id_rezerwacji << ").\n";

    Faktura faktura(nip, id_rezerwacji);
    faktura.oblicz_naleznosc(rezerwacja->getDataPoczatku(),
                             rezerwacja->getDataKonca(), stawka,
                             rezerwacja->getListaUslugDodatkowych());
}

void SystemZarzadzaniaHotelem::dodajUslugeDoRezerwacji(
    int id_rezerwacji, const UslugaDodatkowa& usluga) {
    Rezerwacja* rezerwacja = znajdzRezerwacje(id_rezerwacji);
    if (rezerwacja == nullptr) {
        return;
    }
    rezerwacja->dodajUslugeDodatkowa(usluga);
    std::cout << "  [Usluga] Dodano '" << usluga.getTypUslugi() << "' ("
              << std::fixed << std::setprecision(2) << usluga.getCena()
              << " PLN) do rezerwacji ID: " << id_rezerwacji << "\n";
}

void SystemZarzadzaniaHotelem::wyswietlUzytkownikowPolimorficznie() const {
    std::vector<std::unique_ptr<Osoba>> osoby;
    for (const auto& gosc : lista_gosci_) {
        osoby.push_back(std::make_unique<Gosc>(gosc));
    }
    for (const auto& recepcjonista : lista_recepcjonistow_) {
        osoby.push_back(std::make_unique<Recepcjonista>(recepcjonista));
    }

    std::cout << "  Zarejestrowane osoby w systemie (polimorfizm Osoba):\n";
    for (const auto& osoba : osoby) {
        std::cout << "    - [ID: " << osoba->getId() << "] "
                  << osoba->getImie() << " " << osoba->getNazwisko()
                  << " -> Rola: " << osoba->pobierz_role() << "\n";
    }
}
