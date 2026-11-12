#include "pozycja_rezerwacji.h"

PozycjaRezerwacji::PozycjaRezerwacji(int nr_pokoju)
    : nr_pokoju_(nr_pokoju) {}

PozycjaRezerwacji::~PozycjaRezerwacji() = default;

int PozycjaRezerwacji::getNrPokoju() const {
    return nr_pokoju_;
}
