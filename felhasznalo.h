#pragma once
#include <string>

using namespace std;

class Felhasznalo {
private:
	int szerepkorID;
	string nev;
	string jelszo;

public:
	Felhasznalo();
	Felhasznalo(int _szerepkorID, const string& _nev, const string& _jelszo);
	int getSzerepkorID() const;
	void setSzerepkorID(int id);
	string getNev() const;
	void setNev(string& nev);
	string getJelszo() const;
	void setJelszo(string& ujjelszo);
};
