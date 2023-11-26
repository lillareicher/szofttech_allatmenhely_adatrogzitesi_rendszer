#include "felhasznalo.h"

Felhasznalo::Felhasznalo() : szerepkorID(0), nev(""), jelszo("") {}

Felhasznalo::Felhasznalo(int _szerepkorID, const string& _nev, const string& _jelszo) :
	szerepkorID(_szerepkorID),
	nev(_nev),
	jelszo(_jelszo)
{}

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
