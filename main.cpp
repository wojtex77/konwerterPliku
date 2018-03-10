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
    int iloscLiniiPlikuWejsciowego=daneWejsciowe.size();
    string liniaTekstu="|";
    while (i<iloscLiniiPlikuWejsciowego){
        liniaTekstu.append(daneWejsciowe[i]);
        liniaTekstu.append("|");
        i++;
        if ((i%6)==0){
            daneScalone.push_back(liniaTekstu);
            liniaTekstu="|";
        }
    }
}

int main() {
    vector <string> *danePobranezPliku = new vector <string>(0);
    vector <string> *daneDoZapisuDoPliku = new vector <string>(0);

    wczytajDaneDoVectora(*danePobranezPliku);
    scalajWpisDoJednejLinii(*danePobranezPliku, *daneDoZapisuDoPliku);

    return 0;
}
