#ifndef MENADZERUZYTKOWNIKA_H
#define MENADZERUZYTKOWNIKA_H

#include <iostream>
#include "PlikiUzytkownika.h"
#include <vector>
#include "Uzytkownicy.h"
#include "MetodyPomocnicze.h"

using namespace std;

class MenadzerUzytkownika
{
    int idZalogowanegoUZytkownika;
    Uzytkownik podajDaneNowegoUzytkownika(vector <Uzytkownik> &uzytkownicy);
    int pobierzIdNowegoUzytkownika(vector <Uzytkownik> &uzytkownicy);
    bool czyIstniejeLogin(vector <Uzytkownik> &uzytkownicy, string login);
    PlikiUzytkownika plik;
    MetodyPomocnicze metoda;
public:
    vector <Uzytkownik> uzytkownicy;
    MenadzerUzytkownika(string nazwaPlikuUzytkownicy)
        :plik(nazwaPlikuUzytkownicy), metoda(nazwaPlikuUzytkownicy)
    {
        idZalogowanegoUZytkownika=0;
        plik.wczytajUzytkownikowZPliku(uzytkownicy);
    };

    int pobierzIdZalogowanego();
    int wylogowywanie();
    void rejestracjaUzytkownika(vector <Uzytkownik> &uzytkownicy);
    int logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy);
    void zmianaHaslaZalogowanegoUzytkownika();
};









#endif // MENADZERUZYTKOWNIKA_H
