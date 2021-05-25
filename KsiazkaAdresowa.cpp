#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami):
	uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
	NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
{	
	adresatMenedzer = NULL;
}

KsiazkaAdresowa::~KsiazkaAdresowa() {
	delete adresatMenedzer;
	adresatMenedzer = NULL;
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {

	uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {	
	uzytkownikMenedzer.logowanieUzytkownika();
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
	{
		adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
	}
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
	uzytkownikMenedzer.wylogowanieUzytkownika();
	delete adresatMenedzer;
	adresatMenedzer = NULL;
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::dodajAdresata() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->dodajAdresata();
	}
	else {
		cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {	
	adresatMenedzer->wyswietlWszystkichAdresatow();	
}
