#include "recepcjonista.h"

Recepcjonista::Recepcjonista(int id, const std::string& imie,
                             const std::string& nazwisko,
                             int id_recepcjonisty,
                             const std::string& data_zatrudnienia,
                             double pensja)
    : Osoba(id, imie, nazwisko),
      id_recepcjonisty_(id_recepcjonisty),
      data_zatrudnienia_(data_zatrudnienia),
      pensja_(pensja) {}

Recepcjonista::~Recepcjonista() = default;

std::string Recepcjonista::pobierz_role() const {
    return "Recepcjonista";
}

int Recepcjonista::getIdRecepcjonisty() const {
    return id_recepcjonisty_;
}

std::string Recepcjonista::getDataZatrudnienia() const {
    return data_zatrudnienia_;
}

double Recepcjonista::getPensja() const {
    return pensja_;
}
