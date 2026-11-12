#ifndef POKOJ_H
#define POKOJ_H

#include <string>
#include <utility>
#include <vector>

class Pokoj {
public:
    Pokoj(int nr_pokoju, int ilosc_lozek, float stawka_za_dobe);
    ~Pokoj();

    bool czy_dostepny(const std::string& data_poczatku,
                      const std::string& data_konca) const;
    void zablokujTermin(const std::string& data_poczatku,
                        const std::string& data_konca);
    void zwolnijTermin(const std::string& data_poczatku,
                       const std::string& data_konca);

    int getNrPokoju() const;
    int getIloscLozek() const;
    float getStawkaZaDobe() const;

private:
    int nr_pokoju_;
    int ilosc_lozek_;
    float stawka_za_dobe_;
    std::vector<std::pair<std::string, std::string>> zarezerwowane_terminy_;
};

#endif
