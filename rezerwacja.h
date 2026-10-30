#ifndef REZERWACJA_H
#define REZERWACJA_H

#include <string>
#include <vector>
#include <memory>
#include "pozycja_rezerwacji.h" // klasa wynikająca z kompozycji na diagramie
#include "usluga_dodatkowa.h"

class Rezerwacja {
private:
    int id_rezerwacji;
    std::string dataPoczatku;
    std::string dataKonca;
    int pozycjaRezerwacji; // lub powiązanie z obiektem PozycjaRezerwacji
    std::string stanRezerwacji; // np. "zlozona", "anulowana", "zameldowana", "zakonczona"
    std::vector<UslugaDodatkowa> listaUslugDodatkowych;

public:
    Rezerwacja(int id_rezerwacji, const std::string& dataPoczatku, const std::string& dataKonca, int pozycjaRezerwacji);
    ~Rezerwacja() = default;

    // Metody modyfikujące stan i powiązane z User Stories:
    void zmienStan(const std::string& nowyStan);
    void dodajUslugeDodatkowa(const UslugaDodatkowa& usluga);

    // Gettery:
    int getIdRezerwacji() const;
    std::string getDataPoczatku() const;
    std::string getDataKonca() const;
    std::string getStanRezerwacji() const;
    const std::vector<UslugaDodatkowa>& getListaUslugDodatkowych() const;
};

#endif