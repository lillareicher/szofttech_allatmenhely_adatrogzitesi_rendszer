#pragma once
#include <string>

#include "regisztraltfelhasznalo.h"

using namespace std;

class Alkalmazott
{
public:
	static void addFelhasznaloFigyelmeztetes(const string& felhasznalo);
	static void keszletFeltoltesiIgeny();
	static void adatFeltoltes(const string& allatnev);
	static void rangNoveles(const string& felhasznalo, int osszeg);
};

