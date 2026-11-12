#ifndef POZYCJA_REZERWACJI_H
#define POZYCJA_REZERWACJI_H

class PozycjaRezerwacji {
public:
    explicit PozycjaRezerwacji(int nr_pokoju);
    ~PozycjaRezerwacji();

    int getNrPokoju() const;

private:
    int nr_pokoju_;
};

#endif
