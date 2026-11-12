#include "osoba.h"

Osoba::Osoba(int id, const std::string& imie, const std::string& nazwisko)
    : imie_(imie), nazwisko_(nazwisko), id_(id) {}

Osoba::~Osoba() = default;

int Osoba::getId() const {
    return id_;
}

std::string Osoba::getImie() const {
    return imie_;
}

std::string Osoba::getNazwisko() const {
    return nazwisko_;
}
