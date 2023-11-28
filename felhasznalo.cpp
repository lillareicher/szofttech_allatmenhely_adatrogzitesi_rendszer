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

bool Felhasznalo::egyUgyintezoVan()
{
    bool talalt = 0;
    int talalatok = 0;
    ifstream inputFile("felhasznalok.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo, egy;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (szerep == 2 && nev!="") {
                talalt = true;
                talalatok++;
            }

        }
        inputFile.close();
    }
    if (talalatok == 1) {
        return talalt;
    }
    return false;
}

void Felhasznalo::addUgyintezoEgyenleg(int ertek)
{
    ofstream outPutFile("temp.txt", ios::app);
    ifstream inputFile("felhasznalok.txt");
    if (egyUgyintezoVan() == true) {
        if (outPutFile.is_open() && inputFile.is_open()) {
            while (!inputFile.eof()) {
                string nev, jelszo;
                int szerep, rang, menhelye, rangSzamlalo, egy;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (nev != "") {
                    if (szerep == 2) {
                        outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egy << " " << menhelye + ertek << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }
                    else {
                        outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egy << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }
                }

            }
        }
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }
}

int Felhasznalo::getRangSzamlalo(const string& felhasznalonev)
{
    ifstream inputFile("felhasznalok.txt");
    int rangsz = -1;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo, egy;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (felhasznalonev == nev) {
                rangsz = rangSzamlalo;
            }
        }

    }
    inputFile.close();
    return rangsz;
}

int Felhasznalo::getRang(const string& felhasznalonev)
{
    ifstream inputFile("felhasznalok.txt");
    int rangsz = -1;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, jelszo;
            int szerep, rang, menhelye, rangSzamlalo, egy;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (felhasznalonev == nev) {
                rangsz = rang;
            }
        }

    }
    inputFile.close();
    return rangsz;
}
