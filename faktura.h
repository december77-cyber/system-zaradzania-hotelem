#ifndef FAKTURA_H
#define FAKTURA_H

#include <string>
#include <vector>
#include "usluga_dodatkowa.h"

class Faktura {
private:
    std::string NIP;
    int id_rezerwacji;

public:
    Faktura(const std::string& nip, int id_rezerwacji);
    ~Faktura() = default;

    float oblicz_naleznosc(int dataPoczatku, int dataKonca, float stawkaZaDobe, const std::vector<UslugaDodatkowa>& dodatkoweUslugi) const;
};

#endif