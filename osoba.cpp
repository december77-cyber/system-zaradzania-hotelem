#include "osoba.h"

Osoba::Osoba(int id, const std::string& imie, const std::string& nazwisko)
    : imie(imie), nazwisko(nazwisko), id(id) {}

int Osoba::getId() const {
    return id;
}

std::string Osoba::getImie() const {
    return imie;
}

std::string Osoba::getNazwisko() const {
    return nazwisko;
}