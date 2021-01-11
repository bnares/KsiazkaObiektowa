#include <iostream>
#include "Ksiazka.h"

using namespace std;




void Ksiazka:: rejestracjaUzytkownika()
{
    menadzerUzytkownika.rejestracjaUzytkownika(menadzerUzytkownika.uzytkownicy);

}


void Ksiazka:: logowanieUzytkownika()
{
    menadzerUzytkownika.logowanieUzytkownika(menadzerUzytkownika.uzytkownicy);
    cout<<"id zalogowanego uzytkownika z funkcji :"<<menadzerUzytkownika.pobierzIdZalogowanego()<<endl;
    system("pause");
    if(menadzerUzytkownika.pobierzIdZalogowanego() != 0)
    {
        menadzerAdresat = new MenadzerAdresat(menadzerUzytkownika.pobierzIdZalogowanego(), NAZWA_PLIKU_ADRESACI);
    }
}


int Ksiazka:: wyswietlZalogowanegoId()
{
    return menadzerUzytkownika.pobierzIdZalogowanego();
}


void Ksiazka:: dodajNowegoAdresata()
{
    menadzerAdresat -> dodajAdresata();
}


void Ksiazka:: zmienHasloUzytkownika()
{
    menadzerUzytkownika.zmianaHaslaZalogowanegoUzytkownika();

}



int Ksiazka:: wyloguj()
{
   return menadzerUzytkownika.wylogowywanie();
}


void Ksiazka:: wyszukajPoImieniu()
{
   menadzerAdresat -> wyszukajAdresatowPoImieniu();
}



void Ksiazka:: wyszukajPoNazwisku()
{
    menadzerAdresat ->wyszukajAdresatowPoNazwisku();
}



void Ksiazka:: wyswietlWszystkich()
{
    menadzerAdresat ->wyswietlWszystkichAdresatow();
}



int Ksiazka:: usunWybranegoAdresata()
{
    return menadzerAdresat ->usunAdresata();
}

void Ksiazka:: edytujDanegoAdresata()
{
    menadzerAdresat ->edytujAdresata();
}




