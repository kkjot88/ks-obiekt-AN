#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");         
    
    int x = ksiazkaAdresowa.logowanieUzytkownika(); 

    cout << x << endl;

    return 0;
}
