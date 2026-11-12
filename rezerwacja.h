#ifndef REZERWACJA_H
#define REZERWACJA_H

#include <string>
#include <vector>
#include "pozycja_rezerwacji.h"
#include "usluga_dodatkowa.h"

class Rezerwacja {
public:
    Rezerwacja(int id_rezerwacji, int id_goscia,
               const std::string& data_poczatku,
               const std::string& data_konca,
               const PozycjaRezerwacji& pozycja_rezerwacji);
    ~Rezerwacja();

    void zmienStan(const std::string& nowy_stan);
    void dodajUslugeDodatkowa(const UslugaDodatkowa& usluga);

    int getIdRezerwacji() const;
    int getIdGoscia() const;
    int getNrPokoju() const;
    std::string getDataPoczatku() const;
    std::string getDataKonca() const;
    std::string getStanRezerwacji() const;
    const std::vector<UslugaDodatkowa>& getListaUslugDodatkowych() const;

private:
    int id_rezerwacji_;
    int id_goscia_;
    std::string data_poczatku_;
    std::string data_konca_;
    PozycjaRezerwacji pozycja_rezerwacji_;
    std::string stan_rezerwacji_;
    std::vector<UslugaDodatkowa> lista_uslug_dodatkowych_;
};

#endif
