#include <iostream>
#include "MetodyPomocnicze.h"


using namespace std;

string MetodyPomocnicze:: wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}


string MetodyPomocnicze:: konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze:: zwrocStalaKLasy()
{
    return NAZWA_PLIKU_TEKSTOWEGO;
}


/*
bool MetodyPomocnicze:: czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

*/

int MetodyPomocnicze:: konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}


string MetodyPomocnicze:: pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}


string MetodyPomocnicze:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
   if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


char MetodyPomocnicze:: wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}


int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string liczba="";
    int wynik= 0;
    while(true)
    {
        getline(cin, liczba);
        stringstream ss(liczba);

        if(ss>>wynik)
        {
            return wynik;
            break;
        }
        else
        {
            cout<<"to nie jest liczba"<<endl;
        }
    }
}
