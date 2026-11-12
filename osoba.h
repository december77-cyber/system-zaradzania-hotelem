#ifndef OSOBA_H
#define OSOBA_H

#include <string>

class Osoba {
protected:
    std::string imie;
    std::string nazwisko;
    int id;

public:
    Osoba(int id, const std::string& imie, const std::string& nazwisko);
    virtual ~Osoba() = default;

    // Metoda czysto wirtualna wymagana przez Diagram Klas (<<abstract>>):
    virtual std::string pobierz_role() const = 0;

    // Gettery pomocnicze do odczytu pól w innych klasach:
    int getId() const;
    std::string getImie() const;
    std::string getNazwisko() const;
};

#endif