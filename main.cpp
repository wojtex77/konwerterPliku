#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

string deklarowanieNazwyPlikuBazowego (){
    string nazwa;
    cout << "Podaj nazwe pliku do konwersji z rozszerzeniem: ";
    cin >> nazwa;
    return nazwa;
}

string wczytajDaneDoVectora(vector <string> &dane) {
    string nazwaPlikuStringiem = deklarowanieNazwyPlikuBazowego();
    char *nazwaPliku = &nazwaPlikuStringiem[0u];
    fstream plik;
    string pojedynczaLinia;
    plik.open(nazwaPliku,ios::in);
    if (plik.good() == true) {
        while (!plik.eof()) {
            getline(plik,pojedynczaLinia);
            dane.push_back(pojedynczaLinia);
        }
        plik.close();
        plik.clear();
    }
    return nazwaPlikuStringiem;
}

void scalajWpisDoJednejLinii (vector <string> &daneWejsciowe, vector <string> &daneScalone){
    int i=0;
    int iloscLiniiPlikuWejsciowego=daneWejsciowe.size();
    string liniaTekstu="";
    while (i<iloscLiniiPlikuWejsciowego){
        liniaTekstu.append(daneWejsciowe[i]);
        liniaTekstu.append("|");
        i++;
        if ((i%6)==0){
            daneScalone.push_back(liniaTekstu);
            liniaTekstu="";
        }
    }
}

void zapiszScalonyVectorDoNowegoPliku (vector <string> &daneScalone, string nazwaPlikuWejsciowego){
    int dlugoscNazwy=nazwaPlikuWejsciowego.length();
    nazwaPlikuWejsciowego.erase (dlugoscNazwy-4,4);
    nazwaPlikuWejsciowego.append("_nowy_format.txt");
    char *nazwaPliku = &nazwaPlikuWejsciowego[0u];
    int iloscLiniiDanychScalonych=daneScalone.size();
    fstream nowyPlik;
    nowyPlik.open(nazwaPliku,ios::out | ios::app);
    if (nowyPlik.good() == true) {
        for (int i=0; i<iloscLiniiDanychScalonych; i++){
            nowyPlik<<daneScalone[i]<<endl;
        }
    } else cout << "wystapil problem z plikiem";
    nowyPlik.close();
    nowyPlik.clear();
}



int main() {
    vector <string> *danePobranezPliku = new vector <string>(0);
    vector <string> *daneDoZapisuDoPliku = new vector <string>(0);

    string nazwaPlikuWejsciowego;
    nazwaPlikuWejsciowego=wczytajDaneDoVectora(*danePobranezPliku);
    scalajWpisDoJednejLinii(*danePobranezPliku, *daneDoZapisuDoPliku);
    zapiszScalonyVectorDoNowegoPliku(*daneDoZapisuDoPliku,nazwaPlikuWejsciowego);

    return 0;
}
