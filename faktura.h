#ifndef FAKTURA_H
#define FAKTURA_H

#include <string>
#include <vector>
#include "usluga_dodatkowa.h"

class Faktura {
private:
    std::string nipKlienta;
    int idRezerwacji;
    float kwotaCalkowita;

public:
    Faktura(const std::string& nip, int idRezerwacji);
    ~Faktura() = default;

    float oblicz_naleznosc(int liczbaDni, float stawkaZaDobe, const std::vector<UslugaDodatkowa>& uslugi);
    void wyswietlFakture() const;
    float getKwotaCalkowita() const;
};

#endif