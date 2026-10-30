#include "recepcjonista.h"

Recepcjonista::Recepcjonista(int id, const std::string& imie, const std::string& nazwisko,
                             int id_recepcjonisty, const std::string& dataZatrudnienia, double pensja)
    : Osoba(id, imie, nazwisko), id_recepcjonisty(id_recepcjonisty),
      dataZatrudnienia(dataZatrudnienia), pensja(pensja) {}

std::string Recepcjonista::pobierz_role() const {
    return "Recepcjonista";
}

int Recepcjonista::getIdRecepcjonisty() const {
    return id_recepcjonisty;
}

std::string Recepcjonista::getDataZatrudnienia() const {
    return dataZatrudnienia;
}

double Recepcjonista::getPensja() const {
    return pensja;
}