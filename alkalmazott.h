#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "regisztraltfelhasznalo.h"
#include "rang.h"
#include "felhasznalo.h"
#include "allatok.h"

using namespace std;

class Alkalmazott : public Felhasznalo
{
public:
	static void addFelhasznaloFigyelmeztetes(const string &felhasznalonev);
	static void keszletFeltoltesiIgeny(const string& felhasznalonev);
	static void addRangSzamlalo(const string& fnev);
	static void rangSzamlaloBeallitas(const string& felhasznalonev);
	static void felhasznaloListaz();
	static void allatAdatFeltoltes();
};

