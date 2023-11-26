#pragma once
#include <string>

using namespace std;

class AllatMenhely {
public:
	static bool validBejelentkezes(const string& felhasznalonev, const string& jelszo);
	static void regisztracio(const string& felhasznalonev, const string& jelszo);
	static void visszaABeRegMenube();
	static void kilepes();
	static void bejelentkezes();
	static void regisztracio();
};