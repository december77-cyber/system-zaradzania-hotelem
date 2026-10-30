#include "rezerwacja.h"

Rezerwacja::Rezerwacja(int id_rezerwacji, const std::string& dataPoczatku, const std::string& dataKonca, int pozycjaRezerwacji)
    : id_rezerwacji(id_rezerwacji), dataPoczatku(dataPoczatku), dataKonca(dataKonca),
      pozycjaRezerwacji(pozycjaRezerwacji), stanRezerwacji("zlozona") {}

void Rezerwacja::zmienStan(const std::string& nowyStan) {
    stanRezerwacji = nowyStan;
}

void Rezerwacja::dodajUslugeDodatkowa(const UslugaDodatkowa& usluga) {
    listaUslugDodatkowych.push_back(usluga);
}

int Rezerwacja::getIdRezerwacji() const {
    return id_rezerwacji;
}

std::string Rezerwacja::getDataPoczatku() const {
    return dataPoczatku;
}

std::string Rezerwacja::getDataKonca() const {
    return dataKonca;
}

std::string Rezerwacja::getStanRezerwacji() const {
    return stanRezerwacji;
}

const std::vector<UslugaDodatkowa>& Rezerwacja::getListaUslugDodatkowych() const {
    return listaUslugDodatkowych;
}