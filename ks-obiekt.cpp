#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");         
    
    ksiazkaAdresowa.logowanieUzytkownika(); 
    cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() << endl;

    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    ksiazkaAdresowa.logowanieUzytkownika();
    cout << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() << endl;

    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
}
