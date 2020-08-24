#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
       Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto za\210o\276ono pomy\230lnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout<< "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj has\210o: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin()==login)
        {
            cout<<endl<<"Istnieje u\276ytkownik o takim loginie!"<<endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
       for (int i=0; i<uzytkownicy.size(); i++)
    {
        {
            cout<<uzytkownicy[i].pobierzId()<<endl;
            cout<<uzytkownicy[i].pobierzLogin()<<endl;
            cout<<uzytkownicy[i].pobierzHaslo()<<endl;
        }
    }
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login="", haslo = "";

    cout << endl << "Podaj login: ";
    login=MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin()==login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj has\210o. Pozosta\210o pr\242b: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo()==haslo)
                {
                    idZalogowanegoUzytkownika=itr -> pobierzId();
                    cout << endl << "Zalogowa\210es si\251." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy b\210\251dne has\210o." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma u\276ytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cout<<idZalogowanegoUzytkownika<<endl;
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Has\210o zosta\210o zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika=0;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
