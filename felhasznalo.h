#pragma once

#include "hiba.h"

#include <string>

using namespace std;

class Felhasznalo {
private:
    string nev;
    string jelszo;
    bool figyelmeztetes;

public:
    Felhasznalo(const string& _nev, const string& _jelszo);
    string getNev() const;
    void setNev(const string& nev);
    string getJelszo() const;
    void setJelszo(const string& ujjelszo);
    bool getFigyelmeztetes() const;
    void setFigyelmeztetes(bool f);
};