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

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->wyszukajAdresatowPoImieniu();
	}
	else {
		cout << "Aby wyszukac adresatow po imieniu, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->wyszukajAdresatowPoNazwisku();
	}
	else {
		cout << "Aby wyszukac adresatow po nazwisku, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}


void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {	
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->wyswietlWszystkichAdresatow();
	}
	else {
		cout << "Aby wyswietlic wszystkich adresatow, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}	
}

void KsiazkaAdresowa::usunAdresata(){
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->usunAdresata();
	}
	else {
		cout << "Aby usunac adresata, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}
