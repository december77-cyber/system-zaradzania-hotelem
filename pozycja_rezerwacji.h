#ifndef POZYCJA_REZERWACJI_H
#define POZYCJA_REZERWACJI_H

class PozycjaRezerwacji {
private:
    int nrPokoju;

public:
    PozycjaRezerwacji(int nrPokoju) : nrPokoju(nrPokoju) {}
    ~PozycjaRezerwacji() = default;

    int getNrPokoju() const { return nrPokoju; }
};

#endif