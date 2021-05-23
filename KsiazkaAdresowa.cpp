#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
	:uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
	uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {

	uzytkownikMenedzer.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{	
	return uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}