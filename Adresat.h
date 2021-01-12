#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;


class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string adres;
    string email;
    string numerTelefonu;

    public:

        Adresat(string imie="", string nazwisko="", int id = 0, int idUzytkownika=0, string adres = "", string email = "",  string numerTelefonu="")
        {
            this -> imie = imie;
            this -> nazwisko = nazwisko;
            this -> adres = adres;
            this -> email = email;
            this -> numerTelefonu = numerTelefonu;
            this -> id = id;
            this -> idUzytkownika = idUzytkownika;
        }
        void ustawId(int noweId);
        void ustawIdUzytkownika(int noweIdUzytkownika);
        void ustawImie(string noweImie);
        void ustawNazwisko(string noweNazwisko);
        void ustawAdres(string nowyAdres);
        void ustawEmail(string nowyEmail);
        void ustawTelefon(string nowyTelefon);

        int pobierzId();
        int pobierzIdUZytkownika();
        string pobierzImie();
        string pobierzNazwisko();
        string pobierzAdres();
        string pobierzEmail();
        string pobierzTelefon();


};






#endif // ADRESAT_H
