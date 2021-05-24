#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");         
    
    ksiazkaAdresowa.logowanieUzytkownika();     

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
}
