#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "rang.h"


using namespace std;

class Adminisztrator
{
	string nev;
	int szerepkorID;
	string jelszo;
public:
	Adminisztrator(const string& _nev, int _szerepkorID, const string& _jelszo);
	static void felhasznaloTorles(const string& felhasznalonev);
	static void rangAdas(const string &felhasznalonev, int ertek);
	void kervenyFelulvizsgalat();
	static bool letezoFelhasznalo(const string& felhasznalonev);
	static void felhasznaloListaz();
};

#endif