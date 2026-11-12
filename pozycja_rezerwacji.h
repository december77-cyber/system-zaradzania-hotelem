#ifndef POZYCJA_REZERWACJI_H
#define POZYCJA_REZERWACJI_H

class PozycjaRezerwacji {
private:
    int nrPokoju;

public:
    PozycjaRezerwacji(int nrPokoju);
    ~PozycjaRezerwacji() = default;

    int getNrPokoju() const;
};

#endif