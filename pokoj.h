#ifndef POKOJ_H
#define POKOJ_H

#include <string>

class Pokoj {
private:
    // Pola wymagane 1:1 przez Diagram Klas:
    int nrPokoju;
    int iloscLozek;
    float stawkaZaDobe;

public:
    Pokoj(int nrPokoju, int iloscLozek, float stawkaZaDobe);
    ~Pokoj() = default;

    // Metoda wymagana przez Diagram Klas oraz Diagram Sekwencji:
    bool czy_dostepny(const std::string& dataPoczatku, const std::string& dataKonca) const;

    // Gettery potrzebne dla SystemZarzadzaniaHotelem i Faktura:
    int getNrPokoju() const;
    int getIloscLozek() const;
    float getStawkaZaDobe() const;
};

#endif