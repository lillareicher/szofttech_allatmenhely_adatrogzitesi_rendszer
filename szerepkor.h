#ifndef SZEREPKOR_H
#define SZEREPKOR_H

#include <string>
#include "szerepkortipusok.h"
#include "hiba.h"


using namespace std;

class Szerepkor
{
	SzerepkorTipusok tipus;
	int ID;
public:
	Szerepkor(int _ID);
	void setSzerepkorTipusok(int sz);
};

#endif