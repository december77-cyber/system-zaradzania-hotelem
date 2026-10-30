#include "pozycja_rezerwacji.h"

PozycjaRezerwacji::PozycjaRezerwacji(int nrPokoju) 
    : nrPokoju(nrPokoju) {}

int PozycjaRezerwacji::getNrPokoju() const {
    return nrPokoju;
}