#include <iostream>
#include "Ksiazka.h"
#include "Interfejs.h"

using namespace std;




int main()
{
    Ksiazka nowaKsiazka("NowiUzytownicy.txt", "NowiAdresaci.txt");
    Interfejs interfejs("zmienna");
    int zmiennaSterujaca = nowaKsiazka.wyswietlZalogowanegoId();

    while(true)
    {

        if(zmiennaSterujaca==0)
        {

            char wybor = interfejs.wybierzOpcjeZMenuGlownego();
            switch(wybor)
            {
            case '1':
                {
                    nowaKsiazka.rejestracjaUzytkownika();
                    break;
                }
            case '2':
                {
                    nowaKsiazka.logowanieUzytkownika();
                    zmiennaSterujaca = nowaKsiazka.wyswietlZalogowanegoId();
                    break;
                }
            case '9':
                {
                    exit(0);
                }
            }
        }

        else
        {
            char wybor = interfejs.wybierzOpcjeZMenuUzytkownika();
            switch(wybor)
            {
            case '1':
                {
                    nowaKsiazka.dodajNowegoAdresata();
                    break;
                }

            case '2':
                {
                    nowaKsiazka.wyszukajPoImieniu();
                    break;
                }

            case '3':
                {
                    nowaKsiazka.wyszukajPoNazwisku();
                    break;
                }
            case '4':
                {
                    nowaKsiazka.wyswietlWszystkich();
                    break;
                }

            case '5':
                {
                    int IdAdresataUsunieteZeSpisu = nowaKsiazka.usunWybranegoAdresata();  //czy potrzebne jest id Ostatnieego adresata, moze sam void ?

                    break;
                }

            case '6':
                {
                    nowaKsiazka.edytujDanegoAdresata();
                    break;
                }

            case '7':
                {
                    nowaKsiazka.zmienHasloUzytkownika();
                    break;
                }
            case '8':
                {
                    cout<<"Wylogowywanie..."<<endl;
                    zmiennaSterujaca = nowaKsiazka.wyloguj();

                }
            }
        }
    }





    return 0;
}
