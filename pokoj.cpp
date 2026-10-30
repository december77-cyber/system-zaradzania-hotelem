#include "pokoj.h"

Pokoj::Pokoj(int nrPokoju, int iloscLozek, float stawkaZaDobe)
    : nrPokoju(nrPokoju), iloscLozek(iloscLozek), stawkaZaDobe(stawkaZaDobe) {}

bool Pokoj::czy_dostepny(const std::string& dataPoczatku, const std::string& dataKonca) const {
    // Sprawdzenie poprawności przekazanego przedziału dat
    if (dataPoczatku.empty() || dataKonca.empty() || dataPoczatku > dataKonca) {
        return false;
    }
    return true;
}

int Pokoj::getNrPokoju() const {
    return nrPokoju;
}

int Pokoj::getIloscLozek() const {
    return iloscLozek;
}

float Pokoj::getStawkaZaDobe() const {
    return stawkaZaDobe;
}