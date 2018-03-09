#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <conio.h>
#include <vector>


using namespace std;

void wczytajDaneDoStringa(vector <string> &dane){

    fstream plik;
    string pojedynczaLinia;
    plik.open("wpisy.txt",ios::in);
    if (plik.good() == true) {
        while (!plik.eof()) {
            getline(plik,pojedynczaLinia);
            dane.push_back(pojedynczaLinia);
        }
        plik.close();
        plik.clear();
    }
    cout << dane[0] << dane[3];
}

int main()
{
    vector <string> *wczytaneDaneZPliku = new vector <string>(0);
    wczytajDaneDoStringa(*wczytaneDaneZPliku);
    return 0;
}
