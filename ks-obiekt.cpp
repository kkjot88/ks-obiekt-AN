#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");         
    
    ksiazkaAdresowa.logowanieUzytkownika();    

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();    

    return 0;
}
