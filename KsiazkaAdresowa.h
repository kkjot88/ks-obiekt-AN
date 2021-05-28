#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresatMenedzer *adresatMenedzer;	 
	const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
	~KsiazkaAdresowa();

	void wypiszWszystkichUzytkownikow();
		
	char wybierzOpcjeZMenuGlownego();
	void logowanieUzytkownika();	
	void rejestracjaUzytkownika();
	bool czyUzytkownikJestZalogowany();
	//zamknijprogram - poprostu exit	

	char wybierzOpcjeZMenuUzytkownika();
	void dodajAdresata();
	void wyszukajAdresatowPoImieniu();	
	void wyszukajAdresatowPoNazwisku();		
	void wyswietlWszystkichAdresatow();
	void usunAdresata();
	void edytujAdresata();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
};

#endif
