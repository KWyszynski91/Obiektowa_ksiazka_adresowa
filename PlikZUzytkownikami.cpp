#include "PlikZUzytkownikami.h"

//METODY

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPliku.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (PlikTekstowy::czyPlikJestPusty()==true)
        {
            plikTekstowy<<liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy<<endl<<liniaZDanymiUzytkownika;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie uda\210o si\251 otworzy\206 pliku " << nazwaPliku << " i zapisa\206 w nim danych." << endl;
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;

    plikTekstowy.open(nazwaPliku.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plikTekstowy.close();
    }
    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(nazwaPliku.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mo\276na otworzy\206 pliku " << nazwaPliku << endl;
    }
    plikTekstowy.close();
}
