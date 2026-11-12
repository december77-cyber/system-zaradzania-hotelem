#include "faktura.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

Faktura::Faktura(const std::string& nip, int id_rezerwacji)
    : nip_(nip), id_rezerwacji_(id_rezerwacji), kwota_calkowita_(0.0f) {}

Faktura::~Faktura() = default;

int Faktura::obliczLiczbeDni(const std::string& data_poczatku,
                             const std::string& data_konca) const {
    std::tm tm_pocz = {};
    std::tm tm_konc = {};
    std::istringstream ss_pocz(data_poczatku);
    std::istringstream ss_konc(data_konca);

    ss_pocz >> std::get_time(&tm_pocz, "%Y-%m-%d");
    ss_konc >> std::get_time(&tm_konc, "%Y-%m-%d");

    if (ss_pocz.fail() || ss_konc.fail()) {
        return 1;
    }

    std::time_t czas_pocz = std::mktime(&tm_pocz);
    std::time_t czas_konc = std::mktime(&tm_konc);
    if (czas_pocz == -1 || czas_konc == -1) {
        return 1;
    }

    double roznica_sekund = std::difftime(czas_konc, czas_pocz);
    const int SEKUND_W_DOBIE = 86400;
    int dni = static_cast<int>(roznica_sekund / SEKUND_W_DOBIE);
    return (dni > 0) ? dni : 1;
}

float Faktura::oblicz_naleznosc(
    const std::string& data_poczatku,
    const std::string& data_konca,
    float stawka_za_dobe,
    const std::vector<UslugaDodatkowa>& dodatkowe_uslugi) {
    int liczba_dni = obliczLiczbeDni(data_poczatku, data_konca);
    return oblicz_naleznosc(liczba_dni, stawka_za_dobe, dodatkowe_uslugi);
}

float Faktura::oblicz_naleznosc(
    int liczba_dni,
    float stawka_za_dobe,
    const std::vector<UslugaDodatkowa>& dodatkowe_uslugi) {
    int dni_do_rozliczenia = (liczba_dni > 0) ? liczba_dni : 1;
    float koszt_pokoju =
        static_cast<float>(dni_do_rozliczenia) * stawka_za_dobe;
    float koszt_uslug = 0.0f;

    std::cout << " FAKTURA (Rezerwacja ID: " << id_rezerwacji_
              << " NIP: " << nip_ << ")\n";
    std::cout << "  Pobyt: " << dni_do_rozliczenia << " doby x "
              << std::fixed << std::setprecision(2) << stawka_za_dobe
              << " PLN = " << koszt_pokoju << " PLN\n";

    if (!dodatkowe_uslugi.empty()) {
        std::cout << "  Uslugi dodatkowe:\n";
        for (const auto& usluga : dodatkowe_uslugi) {
            std::cout << "    * " << usluga.getTypUslugi() << ": "
                      << usluga.getCena() << " PLN\n";
            koszt_uslug += usluga.getCena();
        }
    } else {
        std::cout << "  Brak zamowionych uslug dodatkowych.\n";
    }

    kwota_calkowita_ = koszt_pokoju + koszt_uslug;
    std::cout << "  SUMA DO ZAPLATY: " << kwota_calkowita_ << " PLN\n";

    return kwota_calkowita_;
}

void Faktura::wyswietlFakture() const {
    std::cout << "[Faktura] NIP: " << nip_
              << " | Rezerwacja: " << id_rezerwacji_
              << " | Kwota: " << std::fixed << std::setprecision(2)
              << kwota_calkowita_ << " PLN\n";
}

std::string Faktura::getNip() const {
    return nip_;
}

int Faktura::getIdRezerwacji() const {
    return id_rezerwacji_;
}

float Faktura::getKwotaCalkowita() const {
    return kwota_calkowita_;
}
