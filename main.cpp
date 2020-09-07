#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaadresowa("Uzytkownicy.txt", "Adresaci.txt");

    //PlikZAdresatami plikZAdresatami("Adresaci.txt");
    //plikZAdresatami.dopisz("tekst do dopisania");
    //PlikZUzytkownikami plikZUzytkownikami("Uzytkownicy.txt");

    char wybor;

    while (true)
    {
        if (ksiazkaadresowa.czyUzytkownikJestZalogowany()==false)
        {
            wybor=ksiazkaadresowa.wybierzOpcjeZMenuGlownego();
            switch(wybor)
                {
                case '1':
                    ksiazkaadresowa.rejestracjaUzytkownika(); break;
                case '2':
                    ksiazkaadresowa.logowanieUzytkownika(); break;
                case '9':
                    exit(0); break;
                default:
                    cout<<endl<<"Nie ma takiej opcji w menu." <<endl<<endl;
                system("pause");
                break;
                }
        }
        else
        {
            wybor=ksiazkaadresowa.wybierzOpcjeZMenuUzytkownika();
            switch(wybor)
            {
            case '1':
                ksiazkaadresowa.dodajAdresata(); break;
            case '2':
                ksiazkaadresowa.wyszukajAdresatowPoImieniu(); break;
            case '3':
                ksiazkaadresowa.wyszukajAdresatowPoNazwisku(); break;
            case '4':
                ksiazkaadresowa.wyswietlWszystkichAdresatow(); break;
            case '5':
                ksiazkaadresowa.usunAdresata(); break;
            case '6':
                ksiazkaadresowa.edytujAdresata(); break;
            case '7':
                ksiazkaadresowa.zmianaHaslaZalogowanegoUzytkownika(); break;
            case '9':
                ksiazkaadresowa.wylogowanieUzytkownika(); break;
            }
        }
    }
    return 0;
}
