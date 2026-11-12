#ifndef SYSTEM_ZARZADZANIA_HOTELEM_H
#define SYSTEM_ZARZADZANIA_HOTELEM_H

#include <memory>
#include <string>
#include <vector>
#include "faktura.h"
#include "gosc.h"
#include "osoba.h"
#include "pokoj.h"
#include "recepcjonista.h"
#include "rezerwacja.h"
#include "usluga_dodatkowa.h"

class SystemZarzadzaniaHotelem {
public:
    SystemZarzadzaniaHotelem();
    ~SystemZarzadzaniaHotelem();

    bool zarezerwuj(int id_goscia, int id_pokoju,
                    const std::string& data_poczatku = "2026-07-01",
                    const std::string& data_konca = "2026-07-05");
    void dodaj_pokoj(int id_pokoju, int liczba_lozek);
    void wymelduj(int id_rezerwacji,
                  const std::string& nip = "PL5252525252");
    void zamelduj(int id_rezerwacji);
    std::vector<int> sprawdz_dostepnosc(
        const std::string& data_poczatku,
        const std::string& data_konca) const;
    float nalicz_oplate_manipulacyjna(int id_goscia,
                                      int id_recepcjonisty,
                                      float kwota);
    void anuluj_rezerwacje(int id_rezerwacji);

    void dodajUslugeDoRezerwacji(int id_rezerwacji,
                                 const UslugaDodatkowa& usluga);
    void wyswietlUzytkownikowPolimorficznie() const;

private:
    Pokoj* znajdzPokoj(int nr_pokoju);
    const Pokoj* znajdzPokoj(int nr_pokoju) const;
    Rezerwacja* znajdzRezerwacje(int id_rezerwacji);
    Gosc* znajdzGoscia(int id_goscia);
    Recepcjonista* znajdzRecepcjoniste(int id_recepcjonisty);

    std::vector<Gosc> lista_gosci_;
    std::vector<Recepcjonista> lista_recepcjonistow_;
    std::vector<Pokoj> katalog_pokoi_;
    std::vector<Rezerwacja> aktywne_rezerwacje_;
    int nastepne_id_rezerwacji_;
};

#endif
