#include "felhasznalo.h"

Felhasznalo::Felhasznalo(const string& _nev, const string& _jelszo) :
   nev(_nev), jelszo(_jelszo)
{
}

string Felhasznalo::getNev() const {
    return nev;
}

void Felhasznalo::setNev(string& felh) {
    nev = felh;
}

string Felhasznalo::getJelszo() const {
    return jelszo;
}

void Felhasznalo::setJelszo(string& ujjelszo) {
    jelszo = ujjelszo;
}

bool Felhasznalo::getFigyelmeztetes() const
{
    return figyelmeztetes;
}
void Felhasznalo::setFigyelmeztetes(bool f)
{
    figyelmeztetes = f;
}
