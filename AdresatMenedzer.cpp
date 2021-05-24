#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string nazwaPlikuZAdresatami)
    :plikZAdresatami(nazwaPlikuZAdresatami)
{
    idOstatniegoAdresata = 0;
}

void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    
    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    string imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);   

    cout << "Podaj nazwisko: ";
    string nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    string numerTelefonu = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    string email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    string adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    for (int i = 0; i < adresaci.size(); i++) {
        cout << adresaci[i].pobierzId() << endl;
        cout << adresaci[i].pobierzIdUzytkownika() << endl;
        cout << adresaci[i].pobierzImie() << endl;
        cout << adresaci[i].pobierzNazwisko() << endl;
        cout << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << adresaci[i].pobierzEmail() << endl;
        cout << adresaci[i].pobierzAdres() << endl;
    }
}
