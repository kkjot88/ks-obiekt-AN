#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikTekstowy
{
	const string NAZWA_PLIKU;
public:
	PlikTekstowy(string nazwaPliku);	
	
	string pobierzNazwePliku();
    bool czyPlikJestPusty(); 
};

#endif