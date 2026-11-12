#include "pokoj.h"
#include <algorithm>

Pokoj::Pokoj(int nr_pokoju, int ilosc_lozek, float stawka_za_dobe)
    : nr_pokoju_(nr_pokoju),
      ilosc_lozek_(ilosc_lozek),
      stawka_za_dobe_(stawka_za_dobe) {}

Pokoj::~Pokoj() = default;

bool Pokoj::czy_dostepny(const std::string& data_poczatku,
                         const std::string& data_konca) const {
    if (data_poczatku.empty() || data_konca.empty() ||
        data_poczatku >= data_konca) {
        return false;
    }

    for (const auto& termin : zarezerwowane_terminy_) {
        const std::string& zajety_od = termin.first;
        const std::string& zajety_do = termin.second;
        if (data_poczatku < zajety_do && zajety_od < data_konca) {
            return false;
        }
    }

    return true;
}

void Pokoj::zablokujTermin(const std::string& data_poczatku,
                           const std::string& data_konca) {
    zarezerwowane_terminy_.emplace_back(data_poczatku, data_konca);
}

void Pokoj::zwolnijTermin(const std::string& data_poczatku,
                          const std::string& data_konca) {
    for (auto it = zarezerwowane_terminy_.begin();
         it != zarezerwowane_terminy_.end(); ++it) {
        if (it->first == data_poczatku && it->second == data_konca) {
            zarezerwowane_terminy_.erase(it);
            return;
        }
    }
}

int Pokoj::getNrPokoju() const {
    return nr_pokoju_;
}

int Pokoj::getIloscLozek() const {
    return ilosc_lozek_;
}

float Pokoj::getStawkaZaDobe() const {
    return stawka_za_dobe_;
}
