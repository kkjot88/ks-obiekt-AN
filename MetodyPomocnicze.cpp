#include "MetodyPomocnicze.h"

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream& plikTekstowy) {    
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    locale loc;    
    while ((isdigit(tekst[pozycjaZnaku],loc)) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku++;
    }
    return liczba;
}
