#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string nazwaPliku;
public:
    PlikTekstowy(string NAZWA_PLIKU) : nazwaPliku(NAZWA_PLIKU) {
    }
    string pobierzNazwePliku();
    bool czyPlikJestPusty();
};

#endif
