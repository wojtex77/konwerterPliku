#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <conio.h>
#include <vector>


using namespace std;

void wczytajDaneDoVectora(vector <string> &dane) {

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
}

void scalajWpisDoJednejLinii (vector <string> &daneWejsciowe, vector <string> &daneScalone){
    int i=0;
    string temp, IDWpisu, imie, nazwiskon telefon, mail, adres;
    while (i<daneWejsciowe.size()){
        IDWpisu=daneWejsciowe[i];
    }
}

int main() {
    vector <string> *danePobranezPliku = new vector <string>(0);
    vector <string> *daneDoZapisuDoPliku = new vector <string>(0);

    wczytajDaneDoVectora(*danePobranezPliku);
    scalajWpisDoJednejLinii(*danePobranezPliku, *daneDoZapisuDoPliku)

    return 0;
}
