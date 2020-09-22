#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    const string nazwaPliku;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "Adresaci_tymczasowo.txt";
    int idOstatniegoAdresata;
    int idUsuwanegoAdresata;
    int idEdytowanegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    int zwrocNumerLiniiSzukanegoAdresata(int idUsuwanegoAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    int pobierzZPlikuIdOstatniegoAdresata();

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
    idOstatniegoAdresata=0;
    };

    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    int usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
    bool czyPlikJestPusty();
};

#endif
