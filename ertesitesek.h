#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

class Ertesitesek
{
public:
	Ertesitesek();
	static void ertesites(const string &nev, const string& targy, const string &ertesites, const string &kuldonev);
	static void ertesitesLekeres(const string& fnev);
	static vector<string> stringFeldarabolas(const string str, const string regex_str);
};

