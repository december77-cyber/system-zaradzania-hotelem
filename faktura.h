#ifndef FAKTURA_H
#define FAKTURA_H

#include <string>
#include <vector>
#include "usluga_dodatkowa.h"

class Faktura {
public:
    Faktura(const std::string& nip, int id_rezerwacji);
    ~Faktura();

    float oblicz_naleznosc(
        const std::string& data_poczatku,
        const std::string& data_konca,
        float stawka_za_dobe,
        const std::vector<UslugaDodatkowa>& dodatkowe_uslugi);

    float oblicz_naleznosc(
        int liczba_dni,
        float stawka_za_dobe,
        const std::vector<UslugaDodatkowa>& dodatkowe_uslugi);

    void wyswietlFakture() const;
    std::string getNip() const;
    int getIdRezerwacji() const;
    float getKwotaCalkowita() const;

private:
    int obliczLiczbeDni(const std::string& data_poczatku,
                        const std::string& data_konca) const;

    std::string nip_;
    int id_rezerwacji_;
    float kwota_calkowita_;
};

#endif
