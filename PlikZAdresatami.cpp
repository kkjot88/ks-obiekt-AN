#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami(string nazwaPlikuZAdresatami)
    :NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
{
    idOstatniegoAdresata = 0;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    vector<Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }    

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);        
    }

    return adresaci;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {    
    return idOstatniegoAdresata;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (MetodyPomocnicze::czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

void PlikZAdresatami::usunAdrestaZPliku(int idAdrestaDoUsuniecia) {
    fstream odczytywanyPlikTekstowy;
    fstream edytowanyPlikTekstowy;    

    const string NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI = NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI = NAZWA_PLIKU_Z_ADRESATAMI.substr(0, NAZWA_PLIKU_Z_ADRESATAMI.find(".txt")) + "_temp.txt";

    odczytywanyPlikTekstowy.open(NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI, ios::in);
    if (odczytywanyPlikTekstowy.good() == false) {
        cout << "error message" << endl;
        return;
    }
    
    edytowanyPlikTekstowy.open(NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI, ios::out);

    string aktualnaLinijkaOdczytywanegoPliku = "";
    string poprzedniaLinijkaOdczytywnaegoPliku = "";
    int licznikLinijek = 0;
    int numerUsunietejLinijki = 0; 

    //zabezpieczone przed zostawieniem ostatniej linjki pustej gdyz taka sytuacja psuje dodawanie adresatow.
    //Do pliku zapisujemy linijke jedna wczesniej niz aktualna po to zeby moc sprawdzac .eof() w obecnej linijce
    //przed dodaniem jej do nowego pliku. Dzieki temu mozemy kontrolowac dodawanie linijki (<< endl;) i uniknac 
    //sytuacji gdy usuwany jest adresat znajdujacy sie w ostatniej linijce a w jego miejsce zostaje dodana pusta linijka.

    while (getline(odczytywanyPlikTekstowy, aktualnaLinijkaOdczytywanegoPliku)) {        
        if (licznikLinijek > 0) {
            int idAdresataPobraneZPoprzedniejLinijkiOdczytywanegoPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(poprzedniaLinijkaOdczytywnaegoPliku);
            if (idAdrestaDoUsuniecia != idAdresataPobraneZPoprzedniejLinijkiOdczytywanegoPliku) {
                edytowanyPlikTekstowy << poprzedniaLinijkaOdczytywnaegoPliku;
                if (!odczytywanyPlikTekstowy.eof()) {
                    edytowanyPlikTekstowy << endl;
                }
            }
            else numerUsunietejLinijki = licznikLinijek;
        }
        if (!odczytywanyPlikTekstowy.eof()) poprzedniaLinijkaOdczytywnaegoPliku = aktualnaLinijkaOdczytywanegoPliku;
        if (odczytywanyPlikTekstowy.eof()) {
            int idAdresataPobraneZAktualnejLinijkiOdczytywanegoPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(aktualnaLinijkaOdczytywanegoPliku);
            if (numerUsunietejLinijki != licznikLinijek && numerUsunietejLinijki != 0) { //zabezpieczenie przed usuwaniem przedostatniej linijki
                edytowanyPlikTekstowy << endl;                
            }                       
            if (idAdrestaDoUsuniecia != idAdresataPobraneZAktualnejLinijkiOdczytywanegoPliku) {
                edytowanyPlikTekstowy << aktualnaLinijkaOdczytywanegoPliku;
            }            
        }
        licznikLinijek++;
    }

    odczytywanyPlikTekstowy.close();
    edytowanyPlikTekstowy.close();

    usunPlik(NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI);
    zmienNazwePliku(NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat) {  
    int idEdytowanegoAdresata = adresat.pobierzId();
    string liniaZNowymiDanymiAdresata = "";
    string aktualnaLinijkaOdczytywanegoPliku;
    fstream odczytywanyPlikTekstowy;
    fstream edytowanyPlikTekstowy;

    const string NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI = NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI = NAZWA_PLIKU_Z_ADRESATAMI.substr(0, NAZWA_PLIKU_Z_ADRESATAMI.find(".txt")) + "_temp.txt";

    liniaZNowymiDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    odczytywanyPlikTekstowy.open(NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI, ios::in);
    if (odczytywanyPlikTekstowy.good() == false) {
        cout << "error message" << endl;
        return;
    }

    edytowanyPlikTekstowy.open(NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI, ios::out);

    while (getline(odczytywanyPlikTekstowy, aktualnaLinijkaOdczytywanegoPliku))
    {
        int idAdresataPobraneZAktualnejLinijkiOdczytywanegoPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(aktualnaLinijkaOdczytywanegoPliku);
        if (idEdytowanegoAdresata == idAdresataPobraneZAktualnejLinijkiOdczytywanegoPliku) {
            edytowanyPlikTekstowy << liniaZNowymiDanymiAdresata;
            if (!odczytywanyPlikTekstowy.eof()) {
                edytowanyPlikTekstowy << endl;
            }
        }
        else {
            edytowanyPlikTekstowy << aktualnaLinijkaOdczytywanegoPliku;
            if (!odczytywanyPlikTekstowy.eof()) {
                edytowanyPlikTekstowy << endl;
            }
        }
    }

    odczytywanyPlikTekstowy.close();
    edytowanyPlikTekstowy.close();

    usunPlik(NAZWA_ODCZYTYWANEGO_PLIKU_Z_ADRESATAMI);
    zmienNazwePliku(NAZWA_EDYTOWANEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
    
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch (numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void PlikZAdresatami::usunPlik(string nazwaPlikuDoUsuniecia) {
    if (remove(nazwaPlikuDoUsuniecia.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuDoUsuniecia << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
