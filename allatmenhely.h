#pragma once
#include <string>
#include "rang.h"
#include "szerepkor.h"
#include <fstream>

using namespace std;

class AllatMenhely {
public:
	static bool validBejelentkezes(const string& felhasznalonev, const string& jelszo);
	static void regisztracio(const string& felhasznalonev, const string& jelszo);
	static void kijelentkezes();
	static void visszaABeRegMenube();
	static void visszaLep();
	static string belepes();
};