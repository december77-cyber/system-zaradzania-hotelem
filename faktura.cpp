#include "faktura.h"
#include <iostream>

Faktura::Faktura(const std::string& nip, int id_rezerwacji)
    : NIP(nip), id_rezerwacji(id_rezerwacji) {}

float Faktura::oblicz_naleznosc(int dataPoczatku, int dataKonca, float stawkaZaDobe, const std::vector<UslugaDodatkowa>& dodatkoweUslugi) const {
    int liczbaDob = dataKonca - dataPoczatku;
    if (liczbaDob <= 0) {
        liczbaDob = 1;
    }

    float naleznosc = liczbaDob * stawkaZaDobe;

    for (const auto& usluga : dodatkoweUslugi) {
        naleznosc += usluga.getCena(); // suma cen usług dodatkowych
    }

    std::cout << "Faktura dla rezerwacji ID: " << id_rezerwacji
              << " | NIP: " << NIP
              << " | Naleznosc: " << naleznosc << " PLN\n";

    return naleznosc;
}