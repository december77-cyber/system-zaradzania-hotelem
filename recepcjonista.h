#ifndef RECEPCJONISTA_H
#define RECEPCJONISTA_H

#include "osoba.h"
#include <string>

class Recepcjonista : public Osoba {
private:
    int id_recepcjonisty;
    std::string dataZatrudnienia;
    double pensja;

public:
    Recepcjonista(int id, const std::string& imie, const std::string& nazwisko,
                  int id_recepcjonisty, const std::string& dataZatrudnienia, double pensja);
    ~Recepcjonista() override = default;

    // Metoda wymagana przez Diagram Klas (polimorfizm z klasy Osoba):
    std::string pobierz_role() const override;

    // Gettery:
    int getIdRecepcjonisty() const;
    std::string getDataZatrudnienia() const;
    double getPensja() const;
};

#endif