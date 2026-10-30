#ifndef SYSTEM_ZARZADZANIA_HOTELEM_H
#define SYSTEM_ZARZADZANIA_HOTELEM_H

#include <vector>
#include <string>
#include "gosc.h"
#include "recepcjonista.h"
#include "pokoj.h"
#include "rezerwacja.h"
#include "faktura.h"

class SystemZarzadzaniaHotelem {
private:
    std::vector<Gosc> listaGosci;
    std::vector<Recepcjonista> listaRecepcjonistow;
    std::vector<Pokoj> katalogPokoi;
    std::vector<Rezerwacja> aktywneRezerwacje;

public:
    SystemZarzadzaniaHotelem() = default;
    ~SystemZarzadzaniaHotelem() = default;

    // Metody z Diagramu Klas:
    void zarezerwuj(int id_goscia, int id_pokoju);
    void dodaj_pokoj(int id_pokoju, int liczba_lozek);
    void wymelduj(int id_rezerwacji);
    void zamelduj(int id_rezerwacji);
    void sprawdz_dostepnosc(const std::string& data_poczatku, const std::string& data_konca);
    void nalicz_oplate_manipulacyjna(int id_goscia, int id_recepjonisty, float kwota);
    void anuluj_rezerwacje(int id_rezerwacji);
};

#endif