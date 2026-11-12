#ifndef RECEPCJONISTA_H
#define RECEPCJONISTA_H

#include <string>
#include "osoba.h"

class Recepcjonista : public Osoba {
public:
    Recepcjonista(int id, const std::string& imie,
                  const std::string& nazwisko, int id_recepcjonisty,
                  const std::string& data_zatrudnienia, double pensja);
    ~Recepcjonista() override;

    std::string pobierz_role() const override;

    int getIdRecepcjonisty() const;
    std::string getDataZatrudnienia() const;
    double getPensja() const;

private:
    int id_recepcjonisty_;
    std::string data_zatrudnienia_;
    double pensja_;
};

#endif
