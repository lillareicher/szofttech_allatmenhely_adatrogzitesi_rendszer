#pragma once

#include "hiba.h"
#include "ertesitesek.h"
#include "idopontok.h"

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Felhasznalo {
private:
    string nev;
    bool figyelmeztetes;
    int rangSzamlalo;
public:
    Felhasznalo() = default;
    Felhasznalo(const string& _nev, const string& _jelszo);
    string getNev() const;
    void setNev(string& nev);
    bool getFigyelmeztetes() const;
    static bool egyUgyintezoVan();
    static void addMenhelyEgyenleg(int ertek);
    static int getRangSzamlalo(const string& felhasznalonev);
    static int getRang(const string& felhasznalonev);
};