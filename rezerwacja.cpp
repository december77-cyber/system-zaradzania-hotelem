#include "rezerwacja.h"

Rezerwacja::Rezerwacja(int id_rezerwacji, int id_goscia,
                       const std::string& data_poczatku,
                       const std::string& data_konca,
                       const PozycjaRezerwacji& pozycja_rezerwacji)
    : id_rezerwacji_(id_rezerwacji),
      id_goscia_(id_goscia),
      data_poczatku_(data_poczatku),
      data_konca_(data_konca),
      pozycja_rezerwacji_(pozycja_rezerwacji),
      stan_rezerwacji_("zlozona") {}

Rezerwacja::~Rezerwacja() = default;

void Rezerwacja::zmienStan(const std::string& nowy_stan) {
    stan_rezerwacji_ = nowy_stan;
}

void Rezerwacja::dodajUslugeDodatkowa(const UslugaDodatkowa& usluga) {
    lista_uslug_dodatkowych_.push_back(usluga);
}

int Rezerwacja::getIdRezerwacji() const {
    return id_rezerwacji_;
}

int Rezerwacja::getIdGoscia() const {
    return id_goscia_;
}

int Rezerwacja::getNrPokoju() const {
    return pozycja_rezerwacji_.getNrPokoju();
}

std::string Rezerwacja::getDataPoczatku() const {
    return data_poczatku_;
}

std::string Rezerwacja::getDataKonca() const {
    return data_konca_;
}

std::string Rezerwacja::getStanRezerwacji() const {
    return stan_rezerwacji_;
}

const std::vector<UslugaDodatkowa>&
Rezerwacja::getListaUslugDodatkowych() const {
    return lista_uslug_dodatkowych_;
}
