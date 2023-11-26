#include "szerepkor.h"

SzerepkorTipusok Szerepkor::tipus = SzerepkorTipusok::Regisztralt_Felhasznalo;

Szerepkor::Szerepkor(int _ID): ID(_ID)
{
}

void Szerepkor::setSzerepkorTipusok(int sz)
{
	switch (sz)
	{
		case 0: tipus = SzerepkorTipusok::Admin;
			break;
		case 1: tipus = SzerepkorTipusok::Regisztralt_Felhasznalo;
			break;
		case 2: tipus = SzerepkorTipusok::Ugyintezo;
			break;
		case 3: tipus = SzerepkorTipusok::Alkalmazott;
			break;
		default: throw 0;
	}
}

SzerepkorTipusok Szerepkor::getSzerepkorTipusok()
{
	return tipus;
}

int Szerepkor::getSzerepkor(const string& felhasznalonev)
{

    ifstream inputFile("felhasznalok.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, egyenleg, menhelye;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye;
            if (nev == felhasznalonev) {
                return szerep;
            }
        }
		return 0;
        inputFile.close();
    }
}

