#include "gosc.h"

Gosc::Gosc(int id, const std::string& imie, const std::string& nazwisko)
    : Osoba(id, imie, nazwisko) {}

std::string Gosc::pobierz_role() const {
    return "Gosc";
}