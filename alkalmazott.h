#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "regisztraltfelhasznalo.h"
#include "ertesites.h"
#include "rang.h"
#include "felhasznalo.h"
#include "allatok.h"

using namespace std;

class Alkalmazott : public Felhasznalo
{
public:
	static void addFelhasznaloFigyelmeztetes();
	static void keszletFeltoltesiIgeny();
	static void addRangSzamlalo();
	static void rangSzamlaloBeallitas(const string& felhasznalonev);
	static void felhasznaloListaz();
	static void allatAdatFeltoltes();
};

