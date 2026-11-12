#include "faktura.h"
#include <iostream>
#include <iomanip>

Faktura::Faktura(const std::string& nip, int idRezerwacji)
    : nipKlienta(nip), idRezerwacji(idRezerwacji), kwotaCalkowita(0.0f) {}

float Faktura::oblicz_naleznosc(int liczbaDni, float stawkaZaDobe, const std::vector<UslugaDodatkowa>& uslugi) {
    float kosztPokoju = liczbaDni * stawkaZaDobe;
    float kosztUslug = 0.0f;

    std::cout << "\n--- [LOGIKA BIZNESOWA: OBLICZANIE FAKTURY] ---\n";
    std::cout << "Faktura dla rezerwacji ID: " << idRezerwacji << " | NIP: " << nipKlienta << "\n";
    std::cout << "Pobyt: " << liczbaDni << " dni x " << stawkaZaDobe << " PLN = " << kosztPokoju << " PLN\n";

    if (!uslugi.empty()) {
        std::cout << "Uslugi dodatkowe:\n";
        for (const auto& u : uslugi) {
            std::cout << "  - " << u.getTypUslugi() << ": " << u.getCena() << " PLN\n";
            kosztUslug += u.getCena();
        }
    } else {
        std::cout << "Brak zamowionych uslug dodatkowych.\n";
    }

    kwotaCalkowita = kosztPokoju + kosztUslug;
    std::cout << "SUMA DO ZAPLATY: " << std::fixed << std::setprecision(2) << kwotaCalkowita << " PLN\n";
    std::cout << "---------------------------------------------\n\n";

    return kwotaCalkowita;
}

void Faktura::wyswietlFakture() const {
    std::cout << "[Faktura] NIP: " << nipKlienta 
              << " | Rezerwacja: " << idRezerwacji 
              << " | Kwota: " << kwotaCalkowita << " PLN\n";
}

float Faktura::getKwotaCalkowita() const {
    return kwotaCalkowita;
}