#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;    
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);    
    void wyszukajAdresatowPoImieniu();    
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();

    void wyswietlWszystkichAdresatow();
};

#endif /*ADRESATMENEDZER_H*/
