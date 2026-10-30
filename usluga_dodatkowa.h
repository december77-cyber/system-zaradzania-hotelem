#ifndef USLUGADODATKOWA_H
#define USLUGADODATKOWA_H

#include <string>

class UslugaDodatkowa {
private:
    std::string typUslugi;
    float cena;

public:
    UslugaDodatkowa(const std::string& typUslugi, float cena);
    ~UslugaDodatkowa() = default;

    std::string getTypUslugi() const;
    float getCena() const;
};

#endif