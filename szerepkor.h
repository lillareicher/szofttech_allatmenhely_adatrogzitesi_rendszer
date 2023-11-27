#ifndef SZEREPKOR_H
#define SZEREPKOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "szerepkortipusok.h"
#include "hiba.h"


using namespace std;

class Szerepkor
{
	static SzerepkorTipusok tipus;
public:
	Szerepkor();
	static void setSzerepkorTipusok(int sz);
	static SzerepkorTipusok getSzerepkorTipusok();
	static int getSzerepkor(const string& felhasznalonev);
};

#endif