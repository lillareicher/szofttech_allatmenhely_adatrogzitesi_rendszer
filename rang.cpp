#include "rang.h"

RangTipus Rang::tipus = RangTipus::Kezdo;

Rang::Rang(int _rangID) : rangID(_rangID)
{
}

void Rang::setTipus(int t)
{
    switch (t)
    {
    case 0: tipus = RangTipus::Kezdo;
        break;
    case 1: tipus = RangTipus::Kozep;
        break;
    case 2: tipus = RangTipus::Halado;
        break;
    default: throw 0;
    }
}

void Rang::setRangID(int r)
{
    rangID = r;
}

int Rang::getRangID() const
{
    return rangID;
}

RangTipus Rang::getRangTipus()
{
    return tipus;
}

void Rang::setRang(const string& felhasznalonev, int ujRang)
{
    if (ujRang >= 0 && ujRang < 3) {
        ofstream outPutFile("temp.txt", ios::app);
        ifstream inputFile("felhasznalok.txt");
        if (outPutFile.is_open() && inputFile.is_open()) {
            while (!inputFile.eof()) {
                string nev, jelszo;
                int szerep, rang, menhelye, rangSzamlalo, egy;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (nev != "") {
                    if (nev == felhasznalonev) {
                        outPutFile << nev << " " << jelszo << " " << szerep << " " << ujRang << " " << egy << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }
                    else {
                        outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egy << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }
                }

            }
            inputFile.close();
            remove("felhasznalok.txt");
            outPutFile.close();
            rename("temp.txt", "felhasznalok.txt");
        }
    }
}
