#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <algorithm>

#include "Adresat.h"
#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze {

public:
	static int konwersjaStringNaInt(string liczba);
	static string konwerjsaIntNaString(int liczba);	
	static string wczytajLinie();
	static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif

