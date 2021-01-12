#include <iostream>
#include "PlikiAdresata.h"

using namespace std;


int PlikiAdresata:: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metoda.konwersjaStringNaInt(metoda.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}


Adresat PlikiAdresata:: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawTelefon(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int PlikiAdresata:: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metoda.konwersjaStringNaInt(metoda.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}



vector <Adresat> PlikiAdresata:: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowyy;
    vector <Adresat> adresaci;


    plikTekstowyy.open(NAZWA_PLIKU_ADRESACI.c_str(), ios::in);




    if (plikTekstowyy.good() == true)
    {

        while (getline(plikTekstowyy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {

            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {

                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }

            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;

        }

    }


    plikTekstowyy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        ustawIdOstatniegoAdresata(pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku));
    }


        return adresaci;
}


int PlikiAdresata:: pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikiAdresata:: ustawIdOstatniegoAdresata(int nowaLiczba)
{

    idOstatniegoAdresata = nowaLiczba;
}



string PlikiAdresata:: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += metoda.konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += metoda.konwerjsaIntNaString(adresat.pobierzIdUZytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzTelefon() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}




void PlikiAdresata:: dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_ADRESACI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (metoda.czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}




int PlikiAdresata:: wczytajNumerOstatniegoAdresata()
{

    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    int licznikLinijek = 0;

    plikTekstowy.open(NAZWA_PLIKU_ADRESACI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            licznikLinijek++;
        }

        plikTekstowy.close();
        return licznikLinijek;
    }
    else
    {
        plikTekstowy.close();
        return 0;
    }
}


void PlikiAdresata:: usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikiAdresata:: zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}



void PlikiAdresata:: usunWybranaLinieWPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";


    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_ADRESACI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open("TyczasowiAdresaci.txt", ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {

            int numerIdAdresataWPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);


            if (idUsuwanegoAdresata == numerIdAdresataWPliku) {}
            else
            {
                tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
            }


        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_ADRESACI);
        zmienNazwePliku("TyczasowiAdresaci.txt", NAZWA_PLIKU_ADRESACI);
    }
}


int PlikiAdresata:: zwrocNumerIdZLinijki(string linia)
{
   string tekst= "";
    stringstream ss;
    int pozycja =0;
    while(isdigit(linia[pozycja]))
    {
        tekst += linia[pozycja];
        pozycja++;
    }

    ss<<tekst;
    int wynik;
    ss>>wynik;
    return wynik;
}


void PlikiAdresata:: edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_ADRESACI, ios::in);
    tymczasowyPlikTekstowy.open("TyczasowiAdresaci.txt", ios::out | ios::app);


    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            int numerIdZLinijkiOddzielonejPionowymiKreskami = zwrocNumerIdZLinijki(wczytanaLinia);

            if (numerIdZLinijkiOddzielonejPionowymiKreskami == idEdytowanegoAdresata)
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_ADRESACI);
        zmienNazwePliku("TyczasowiAdresaci.txt", NAZWA_PLIKU_ADRESACI);
    }
}

