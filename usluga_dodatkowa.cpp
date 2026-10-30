#include "usluga_dodatkowa.h"

UslugaDodatkowa::UslugaDodatkowa(const std::string& typUslugi, float cena)
    : typUslugi(typUslugi), cena(cena) {}

std::string UslugaDodatkowa::getTypUslugi() const {
    return typUslugi;
}

float UslugaDodatkowa::getCena() const {
    return cena;
}