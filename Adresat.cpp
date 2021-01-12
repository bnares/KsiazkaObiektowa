#include <iostream>

using namespace std;

#include "Adresat.h"


        void Adresat:: ustawId(int noweId)
        {
            id = noweId;
        }

        void Adresat::ustawIdUzytkownika(int noweIdUzytkownika)
        {
            idUzytkownika = noweIdUzytkownika;
        }

        void Adresat::ustawImie(string noweImie)
        {
            imie = noweImie;
        }

        void Adresat::ustawNazwisko(string noweNazwisko)
        {
            nazwisko = noweNazwisko;
        }

        void Adresat::ustawAdres(string nowyAdres)
        {
            adres = nowyAdres;
        }

        void Adresat::ustawEmail(string nowyEmail)
        {
            email = nowyEmail;
        }

        void Adresat::ustawTelefon(string nowyTelefon)
        {
            numerTelefonu = nowyTelefon;
        }


        int Adresat::pobierzId()
        {
            return id;
        }

        int Adresat::pobierzIdUZytkownika()
        {
            return idUzytkownika;
        }

        string Adresat::pobierzImie()
        {
            return imie;
        }

        string Adresat::pobierzNazwisko()
        {
            return nazwisko;
        }

        string Adresat::pobierzAdres()
        {
            return adres;
        }

        string Adresat::pobierzEmail()
        {
            return email;
        }

        string Adresat::pobierzTelefon()
        {
            return numerTelefonu;
        }
