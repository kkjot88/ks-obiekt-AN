#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
	:uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
	uzytkownikMenedzer.wczytajUzytkownikowZPliku();
	idZalogowanegoUzytkownika = 0;
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
	return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika) {
	idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {

	uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{	
	idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();	
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
	idZalogowanegoUzytkownika = uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::dodajAdresata() {
	adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
	adresatMenedzer.wypiszWszystkichAdresatow();
}
