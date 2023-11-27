#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "kervenyek.h"
#include "rang.h"


using namespace std;

class Adminisztrator
{
	string nev;
	string jelszo;
public:
	Adminisztrator(const string& _nev, int _szerepkorID, const string& _jelszo);
	static void felhasznaloTorles();
	static void rangAdas(const string &felhasznalonev, int ertek);
	static void kervenyFelulvizsgalat(const string &targy);
	static bool letezoFelhasznalo(const string& felhasznalonev);
	static void felhasznaloListaz();
};

#endif