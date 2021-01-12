#ifndef PLIKIADRESATA_H
#define PLIKIADRESATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;


class PlikiAdresata
{
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_ADRESACI;
    MetodyPomocnicze metoda;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int wczytajNumerOstatniegoAdresata();
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int zwrocNumerIdZLinijki(string linia);

    public:
        PlikiAdresata(string nazwaPliku)
            : NAZWA_PLIKU_ADRESACI(nazwaPliku), metoda(nazwaPliku)
            {

                idOstatniegoAdresata = wczytajNumerOstatniegoAdresata();
            };

        vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
        string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
        int pobierzIdOstatniegoAdresata();
        void ustawIdOstatniegoAdresata(int nowaLiczba);
        void dopiszAdresataDoPliku(Adresat adresat);
        void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
        void edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);

};



#endif // PLIKIADRESATA_H
