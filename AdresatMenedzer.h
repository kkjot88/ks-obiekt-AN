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
    int idOstatniegoAdresata;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami);
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);    

    void wypiszWszystkichAdresatow();    
};

#endif /*ADRESATMENEDZER_H*/
