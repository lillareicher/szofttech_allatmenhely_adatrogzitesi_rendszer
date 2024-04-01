#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "kervenyek.h"
#include "rang.h"
#include "felhasznalo.h"
#include "regisztraltfelhasznalo.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Adminisztrator : public Felhasznalo 
{
public:
	Adminisztrator();
	static void felhasznaloTorles(const string& felhasznalonev);
	static void rangAdas(const string &felhasznalonev, int ertek);
	static void kervenyFelulvizsgalat(int testid);
	static bool letezoFelhasznalo(const string& felhasznalonev);
	static void felhasznaloListaz();
	static void szerepkorAdas(const string& felhasznalonev, int ertek);
};

#endif