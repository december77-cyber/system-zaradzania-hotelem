#ifndef GOSC_H
#define GOSC_H

#include "osoba.h"
#include "rezerwacja.h"
#include <string>
#include <vector>

class Gosc : public Osoba {
private:
    std::vector<Rezerwacja> listaRezerwacji;

public:
    Gosc(int id, const std::string& imie, const std::string& nazwisko);
    ~Gosc() = default;

    std::string pobierz_role() const override;
};

#endif