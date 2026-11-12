#ifndef USLUGA_DODATKOWA_H
#define USLUGA_DODATKOWA_H

#include <string>

class UslugaDodatkowa {
public:
    UslugaDodatkowa(const std::string& typ_uslugi, float cena);
    ~UslugaDodatkowa();

    std::string getTypUslugi() const;
    float getCena() const;

private:
    std::string typ_uslugi_;
    float cena_;
};

#endif
