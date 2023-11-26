#pragma once
#include <string>
using namespace std;

class Adminisztrator {
private:
	int szerepkorId;
	string nev;
	string jelszo;
	int id;
public:
	static bool felhasznaloTorles(const string& filename, int id);
	void rangAdas(int id, int randID);
	void kervenyFelulvizsgalat(string& kerveny);

};