#ifndef MENADZERADRESAT_H
#define MENADZERADRESAT_H


#include <iostream>
#include <vector>
#include "Adresat.h"
#include "PlikiAdresata.h"
#include "MetodyPomocnicze.h"
#include "Interfejs.h"

using namespace std;


class MenadzerAdresat
{
    vector <Adresat> adresaci;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    PlikiAdresata plikAdresata;
    MetodyPomocnicze metoda;
    vector <Adresat> pobierzAdresatowZalogowanego();
    Adresat podajDaneNowegoAdresata();
    int idOstatniegoAdresataOkreslonaPodczasWczytywaniaPoczatkowego();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

    public:
        MenadzerAdresat(int idZalogowanego, string nazwaPlikuAdresata)
            : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanego), plikAdresata(nazwaPlikuAdresata), metoda(nazwaPlikuAdresata)
            {
                adresaci = pobierzAdresatowZalogowanego();


            };
        void dodajAdresata();
        void wyszukajAdresatowPoImieniu();
        void wyszukajAdresatowPoNazwisku();
        void wyswietlWszystkichAdresatow();
        int usunAdresata();
        void edytujAdresata();
};

#endif // MENADZERADRESAT_H
