#ifndef OSOBA_H
#define OSOBA_H

#include <string>

class Osoba {
public:
    Osoba(int id, const std::string& imie, const std::string& nazwisko);
    virtual ~Osoba();

    virtual std::string pobierz_role() const = 0;

    int getId() const;
    std::string getImie() const;
    std::string getNazwisko() const;

private:
    std::string imie_;
    std::string nazwisko_;
    int id_;
};

#endif
