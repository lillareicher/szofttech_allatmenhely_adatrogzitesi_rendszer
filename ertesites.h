#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Ertesites
{
	static string uzenet;
public:
	Ertesites();
	static string getUzenet();
	static void ertesit(const string &fnev, const string &uzenet);
};

