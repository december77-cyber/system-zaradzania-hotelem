#include "gosc.h"

Gosc::Gosc(int id, const std::string& imie, const std::string& nazwisko)
    : Osoba(id, imie, nazwisko) {}

Gosc::~Gosc() = default;

std::string Gosc::pobierz_role() const {
    return "Gosc";
}

void Gosc::dodajRezerwacje(const Rezerwacja& rezerwacja) {
    lista_rezerwacji_.push_back(rezerwacja);
}

const std::vector<Rezerwacja>& Gosc::getListaRezerwacji() const {
    return lista_rezerwacji_;
}
