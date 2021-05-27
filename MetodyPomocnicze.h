#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <locale>

#include "Adresat.h"
#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze {

public:
	static int konwersjaStringNaInt(string liczba);
	static string konwerjsaIntNaString(int liczba);	
	static string wczytajLinie();
	static int wczytajLiczbeCalkowita();
	static char wczytajZnak();
	static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	static bool czyPlikJestPusty(fstream& plikTekstowy);
	static string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif

