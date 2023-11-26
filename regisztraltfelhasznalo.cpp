#include "regisztraltfelhasznalo.h"
#include "felhasznalo.h"
#include "idopontok.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Foglalas {
    int id;
    string datum;
};

RegisztraltFelhasznalo::RegisztraltFelhasznalo() {
};


Egyenleg RegisztraltFelhasznalo::getFelhasznaloEgyenleg() const
{
    return felhasznaloEgyenleg;
}

RegisztraltFelhasznalo::RegisztraltFelhasznalo(Rang _rang, Egyenleg _felhasznaloEgyenleg, int _szerepkorID, const string& _nev, const string& _jelszo)
    : Felhasznalo(_szerepkorID, _nev, _jelszo), rang(_rang), 
    felhasznaloEgyenleg(_felhasznaloEgyenleg) 
{}

Egyenleg& Egyenleg::operator+=(const Egyenleg& other) {

    this->egyenleg += other.egyenleg;
    return *this;
}


void RegisztraltFelhasznalo::addFelhasznaloEgyenleg(const Egyenleg& feltoltottEgyenleg) {
    felhasznaloEgyenleg += feltoltottEgyenleg;
}

//void RegisztraltFelhasznalo::onkentesSzabadKilistaz() const
//{
//
//}

Felhasznalo RegisztraltFelhasznalo::felhasznaloBeolvasas(const string& fajlnev) {
    ifstream fajl(fajlnev);

    if (!fajl.is_open()) {
        cerr << "Hiba: Nem sikerult megnyitni a fajlt: " << fajlnev << endl;
        return Felhasznalo();
    }
    string felhasznaloNev;
    fajl >> felhasznaloNev;

    int szerepkorID;
    string nev;
    string jelszo;

    while (fajl >> szerepkorID >> nev >> jelszo) {
        // Itt a felhasznaloNev-t haszn�lom, amit a f�jlb�l olvastunk
        if (nev == felhasznaloNev) {
            fajl.close();
            // Felhasznalo p�ld�ny visszaad�sa, ha megtal�ltuk
            return Felhasznalo(szerepkorID, nev, jelszo);
        }
    }

    fajl.close();
    // �res Felhasznalo p�ld�ny visszaad�sa, ha nem tal�ltuk meg
    return Felhasznalo();
}


//void RegisztraltFelhasznalo::onkentesSzabadKilistaz() {
//    Idopontok idopontok;
//    cout << "Szabad idopontok:\n";
//
//    for (const string& idopont : idopontok.szabadIdopontok) {
//        cout << idopont << endl;
//    }
//}

void RegisztraltFelhasznalo::onkentesIdopontFoglalas(const Felhasznalo& felhasznalo) {
    {

        cout << "Valassz egy idopontot (pl. 2023-01-01 14:00): ";
        string kivalasztottDatum;
        getline(cin, kivalasztottDatum);

        // Ellen�rizz�k, hogy az adott id�pont foglalt-e
        ifstream foglalasokFajl("foglalasok.txt");
        string sor;
        bool foglalt = false;

        while (getline(foglalasokFajl, sor)) {
            size_t found = sor.find(kivalasztottDatum);
            if (found != string::npos) {
                foglalt = true;
                break;
            }
        }

        foglalasokFajl.close();

        if (foglalt) {
            cout << "Az idopont sajnos mar foglalt.\n";
        }
        else {
            // Hozz�adjuk az �j foglal�st a f�jlhoz
            ofstream foglalasokFajlIro("foglalasok.txt", ios::app);
            foglalasokFajlIro << felhasznalo.getNev() << " " << kivalasztottDatum << endl;
            foglalasokFajlIro.close();

            cout << "Sikeres foglalas.\n";
        }
    }
}


