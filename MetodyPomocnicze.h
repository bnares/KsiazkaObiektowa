#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include<fstream>
#include <algorithm>
#include "PlikTekstowy.h"


using namespace std;

class MetodyPomocnicze:public PlikTekstowy
{
    public:
        const string NAZWA_PLIKU_TEKSTOWEGO;
        MetodyPomocnicze(string nazwa): NAZWA_PLIKU_TEKSTOWEGO(nazwa), PlikTekstowy(nazwa){};
        string wczytajLinie();
        string konwerjsaIntNaString(int liczba);
        //bool czyPlikJestPusty(fstream &plikTekstowy);
        int konwersjaStringNaInt(string liczba);
        string pobierzLiczbe(string tekst, int pozycjaZnaku);
        string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
        char wczytajZnak();
        int wczytajLiczbeCalkowita();
        string zwrocStalaKLasy();


};










#endif // METODYPOMOCNICZE_H
