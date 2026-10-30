#include "system_zarzadzania_hotelem.h"
#include <iostream>

void SystemZarzadzaniaHotelem::sprawdz_dostepnosc(const std::string& data_poczatku, const std::string& data_konca) {
    // TODO: zaimplementować logikę sprawdzania dostępności
}

void SystemZarzadzaniaHotelem::zarezerwuj(int id_goscia, int id_pokoju) {
    // TODO: zaimplementować logikę rezerwacji
}

void SystemZarzadzaniaHotelem::anuluj_rezerwacje(int id_rezerwacji) {
    // TODO: zaimplementować logikę anulowania
}

float SystemZarzadzaniaHotelem::nalicz_oplate_manipulacyjna(int id_goscia, int id_recepjonisty, float kwota) {
    // TODO: zaimplementować logikę naliczania opłaty
    return kwota;
}

void SystemZarzadzaniaHotelem::zamelduj(int id_rezerwacji) {
    // TODO: zaimplementować logikę zameldowania
}

void SystemZarzadzaniaHotelem::wymelduj(int id_rezerwacji) {
    // TODO: zaimplementować logikę wymeldowania
}

void SystemZarzadzaniaHotelem::dodaj_pokoj(int id_pokoju, int liczba_lozek) {
    // TODO: zaimplementować logikę dodawania pokoju
}