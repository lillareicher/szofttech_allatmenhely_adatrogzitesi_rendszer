#pragma once
#include <string>

using namespace std;

class Felhasznalo {
private:
    int szerepkorID;
    string nev;
    string jelszo;
    int id;
public:
    Felhasznalo(int _szerepkorID, const string &_nev, const string& _jelszo, int _id);
    int getSzerepkorID() const;
    void setSzerepkorID(int id);
    string getNev() const;
    void setNev(string& nev);
    string getJelszo() const;
    void setJelszo(string& ujjelszo);
    int getID() const;
    void setID(int id);
};
