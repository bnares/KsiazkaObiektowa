#include <iostream>
#include "MenadzerUzytkownika.h"

using namespace std;



bool MenadzerUzytkownika:: czyIstniejeLogin(vector <Uzytkownik> &uzytkownicy, string login)
{
   vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}

int MenadzerUzytkownika:: pobierzIdNowegoUzytkownika(vector <Uzytkownik> &uzytkownicy)
{
   if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}



Uzytkownik MenadzerUzytkownika:: podajDaneNowegoUzytkownika(vector <Uzytkownik> &uzytkownicy)
{

   Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika(uzytkownicy));

    do
    {
        cout << endl << "Podaj login: ";
        uzytkownik.ustawLogin(metoda.wczytajLinie());
    } while (czyIstniejeLogin(uzytkownicy, uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(metoda.wczytajLinie());

    return uzytkownik;
}



void MenadzerUzytkownika:: rejestracjaUzytkownika(vector <Uzytkownik> &uzytkownicy)
{
   Uzytkownik uzytkownik = podajDaneNowegoUzytkownika(uzytkownicy);

    uzytkownicy.push_back(uzytkownik);
    plik.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


int MenadzerUzytkownika:: logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy)
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = metoda.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metoda.wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUZytkownika = itr -> pobierzId();
                    return idZalogowanegoUZytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}



int MenadzerUzytkownika:: pobierzIdZalogowanego()
{
    return idZalogowanegoUZytkownika;
}




void MenadzerUzytkownika:: zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metoda.wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUZytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plik.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}



int  MenadzerUzytkownika:: wylogowywanie()
{
    idZalogowanegoUZytkownika =0;
    return idZalogowanegoUZytkownika;
}
