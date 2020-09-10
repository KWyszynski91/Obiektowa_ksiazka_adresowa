#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami: public PlikTekstowy
{
    const string nazwaPliku;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    //PlikTekstowy plikTekstowy;
public:
    PlikZUzytkownikami(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI):  PlikTekstowy(NAZWA_PLIKU_Z_UZYTKOWNIKAMI)  {}; //LISTA INICJALIZACYJNA
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};

#endif
