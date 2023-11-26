#include "felhasznalo.h"

Felhasznalo::Felhasznalo(int _szerepkorID, const string &_nev, const string &_jelszo, int _id) :
    szerepkorID(_szerepkorID), nev(_nev), jelszo(_jelszo), id(_id)
{

}

int Felhasznalo::getSzerepkorID() const {
    return szerepkorID;
}

void Felhasznalo::setSzerepkorID(int id) {
    szerepkorID = id;
}

string Felhasznalo::getNev() const{
    return nev;
};

void Felhasznalo::setNev(string& felh) {
    nev = felh;
};

string Felhasznalo::getJelszo() const {
    return jelszo;
}

void Felhasznalo::setJelszo(string& ujjelszo) {
    jelszo = ujjelszo;
}

int Felhasznalo::getID() const {
    return id;
};

void Felhasznalo::setID(int _id) {
    id = _id;
};
