#include "egyenleg.h"

Egyenleg::Egyenleg(unsigned _egyenleg) : egyenleg(_egyenleg)
{

}

unsigned Egyenleg::getEgyenleg() const
{
    return egyenleg;
}

void Egyenleg::setEgyenleg(unsigned ujegyenleg)
{
    egyenleg = ujegyenleg;
}

void Egyenleg::setFelhasznaloEgyenleg(const string& felhasznalonev, int ertek)
{

    ofstream outPutFile("temp.txt", ios::app);
    ifstream inputFile("felhasznalok.txt");

    if (outPutFile.is_open() && inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo;
            Egyenleg egyenleg(0);
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg.egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (nev != "") {
                if (nev == felhasznalonev) {
                    outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << ertek << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
                else {
                    outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg.egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
            }

        }
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }
}

int Egyenleg::getMenhelyEgyenleg()
{
    ifstream inputFile("felhasznalok.txt");
    unsigned felhEgyenleg = -1;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo;
            Egyenleg egyenleg(0);
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg.egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (2 == szerep) {
                felhEgyenleg = menhelye;
            }
        }

    }
    inputFile.close();
    return felhEgyenleg;
}

int Egyenleg::getFelhasznaloEgyenleg(const string& felhasznalonev)
{
    ifstream inputFile("felhasznalok.txt");
    unsigned felhEgyenleg = -1;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo;
            Egyenleg egyenleg(0);
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg.egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (felhasznalonev == nev) {
                felhEgyenleg = egyenleg.egyenleg;
            }
        }

    }
    inputFile.close();
    return felhEgyenleg;
}

