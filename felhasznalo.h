#pragma once

#include "hiba.h"
#include "ertesites.h"

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Felhasznalo {
private:
    string nev;
    string jelszo;
    bool figyelmeztetes;
    int rangSzamlalo;
public:
    Felhasznalo(const string& _nev, const string& _jelszo);
    string getNev() const;
    void setNev(string& nev);
    string getJelszo() const;
    void setJelszo(string& ujjelszo);
    bool getFigyelmeztetes() const;
    void setFigyelmeztetes(bool f);
    static bool egyUgyintezoVan();
    static void addUgyintezoEgyenleg(int ertek);
    static int getRangSzamlalo(const string& felhasznalonev);
    static int getRang(const string& felhasznalonev);
};