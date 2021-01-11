#include "PlikTekstowy.h"
#include <iostream>


using namespace std;



string PlikTekstowy:: pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool PlikTekstowy:: czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if(plikTekstowy.good()==true)
    {

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
    }
    else
        return true;
    plikTekstowy.close();
}




