#ifndef GOSC_H
#define GOSC_H

#include <string>
#include <vector>
#include "osoba.h"
#include "rezerwacja.h"

class Gosc : public Osoba {
public:
    Gosc(int id, const std::string& imie, const std::string& nazwisko);
    ~Gosc() override;

    std::string pobierz_role() const override;
    void dodajRezerwacje(const Rezerwacja& rezerwacja);
    const std::vector<Rezerwacja>& getListaRezerwacji() const;

private:
    std::vector<Rezerwacja> lista_rezerwacji_;
};

#endif
