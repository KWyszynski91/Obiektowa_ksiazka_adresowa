#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer=new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer=NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout<<"Aby doda\206 adresata nale\276y si\251 zalogowa\206"<<endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
       if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->wyswietlWszystkichAdresatow();
    }
    else
    {
        cout<<"Aby wy\230wietli\206 kontakty nale\276y si\251 zalogowa\206"<<endl;
        system("pause");
    }
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;
    system("cls");
    cout<<"+=======================+"<<endl;
    cout<<"|===KSI\244\275KA  ADRESOWA===|" << endl;
    cout<<"|____panel_logowania____|" << endl;
    cout<<"| 1. Rejestracja        |"<<endl;
    cout<<"| 2. Logowanie          |"<<endl;
    cout<<"| 9. Zamknij program    |"<<endl;
    cout<<"+=======================+" << endl;
    cin>>wybor;
    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    system("cls");
    cout<<"+==================================+"<<endl;
    cout<<"|=========KSI\244\275KA ADRESOWA=========|" << endl;
    cout<<"|___________panel_g\210\242wny___________|" << endl;
    cout<<"| 1. Dodaj adresata                |"<<endl;
    //cout<<"| 2. Wyszukaj po imieniu           |"<<endl;
    //cout<<"| 3. Wyszukaj po nazwisku          |"<<endl;
    cout<<"| 4. Wy\230wietl wszystkich adresat\242w |"<<endl;
    //cout<<"| 5. Usu\344 adresata                 |"<<endl;
    //cout<<"| 6. Edytuj adresata               |"<<endl;
    cout<<"+==================================+"<<endl;
    cout<<"| 7. Zmie\344 has\210o                   |"<<endl;
    cout<<"| 9. Wyloguj si\251                   |"<<endl;
    cout<<"+==================================+"<<endl;
    cout<<"Tw\242j wyb\242r: ";
    cin>>wybor;
    cout<<"+==================================+"<<endl;
    return wybor;
}
