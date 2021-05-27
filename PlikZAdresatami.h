#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	int idOstatniegoAdresata;

	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	void usunPlik(string nazwaPlikuDoUsuniecia);
	void zmienNazwePliku(string staraNazwa, string nowaNazwa);	
	
public:
	PlikZAdresatami(string nazwaPlikuZAdresatami);	
	vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata();
	bool dopiszAdresataDoPliku(Adresat adresat);
	void usunAdrestaZPliku(int idAdrestaDoUsuniecia);
};

#endif

