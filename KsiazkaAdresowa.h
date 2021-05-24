#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresatMenedzer adresatMenedzer;
	int idZalogowanegoUzytkownika;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);

	int pobierzIdZalogowanegoUzytkownika();
	void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);

	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void wypiszWszystkichUzytkownikow();	

	void dodajAdresata();
	void wypiszWszystkichAdresatow();
};

#endif
