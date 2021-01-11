#ifndef PLIKTEKSTOWT_H
#define PLIKTEKSTOWY_H
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;
    public:
        PlikTekstowy(string nazwaPliku): NAZWA_PLIKU(nazwaPliku){};
        bool czyPlikJestPusty();
        string pobierzNazwePliku();

};




#endif // PLIKTEKSTOWT_H



