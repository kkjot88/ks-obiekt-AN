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

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
	return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
	char wybor;

	system("cls");
	cout << "    >>> MENU  GLOWNE <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Rejestracja" << endl;
	cout << "2. Logowanie" << endl;
	cout << "9. Koniec programu" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	wybor = MetodyPomocnicze::wczytajZnak();

	return wybor;
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

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
	char wybor;

	system("cls");
	cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Dodaj adresata" << endl;
	cout << "2. Wyszukaj po imieniu" << endl;
	cout << "3. Wyszukaj po nazwisku" << endl;
	cout << "4. Wyswietl adresatow" << endl;
	cout << "5. Usun adresata" << endl;
	cout << "6. Edytuj adresata" << endl;
	cout << "---------------------------" << endl;
	cout << "7. Zmien haslo" << endl;
	cout << "8. Wyloguj sie" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	wybor = MetodyPomocnicze::wczytajZnak();

	return wybor;
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

void KsiazkaAdresowa::edytujAdresata() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresatMenedzer->edytujAdresata();
	}
	else {
		cout << "Aby edytowac adresata, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}
