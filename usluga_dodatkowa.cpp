#include "usluga_dodatkowa.h"

UslugaDodatkowa::UslugaDodatkowa(const std::string& typ_uslugi, float cena)
    : typ_uslugi_(typ_uslugi), cena_(cena) {}

UslugaDodatkowa::~UslugaDodatkowa() = default;

std::string UslugaDodatkowa::getTypUslugi() const {
    return typ_uslugi_;
}

float UslugaDodatkowa::getCena() const {
    return cena_;
}
