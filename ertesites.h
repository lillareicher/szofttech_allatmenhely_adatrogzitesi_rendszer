#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Ertesites
{
	static string uzi;
public:
	Ertesites();
	static string getUzenet();
	static void uzenet();
	static void uzenetLekeres(const string& fnev);
	static void ertesites(const string &nev, const string& targy, const string &ertesites);
	static void ertesitesLekeres(const string& fnev);
};

