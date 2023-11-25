#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include <string>

using namespace std;

class Adminisztrator
{
	string nev;
	int szerepkorID;
	string jelszo;
	int ID;
public:
	Adminisztrator(const string& _nev, int _szerepkorID, const string& _jelszo, int _ID);
	void felhasznaloTorles() const;
	void rangAdas();
	void kervenyFelulvizsgalat();
};

#endif