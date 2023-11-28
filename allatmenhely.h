#pragma once
#include <string>
#include "rang.h"
#include "szerepkor.h"
#include <fstream>
#include <conio.h>

using namespace std;

class AllatMenhely {
public:
	static bool validBejelentkezes(const string& felhasznalonev, const string& jelszo);
	static void regisztracio(const string& felhasznalonev, const string& jelszo);
	static void kijelentkezes();
	static void visszaLep();
	static string belepes();
	static bool ellenorizFoglaltFelhasznalonev(const string& felhasznalonev);
};