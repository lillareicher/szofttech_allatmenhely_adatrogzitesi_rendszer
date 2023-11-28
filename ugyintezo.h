#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "felhasznalo.h"

using namespace std;

class Ugyintezo : public Felhasznalo
{
	static int menhelyEgyenleg;
public:
	Ugyintezo() = default;
	static void kervenyListazas();
	static void kervenyElfogadas();
	static void kervenyElutasitas();
	void addIdopont();
	static void setMenhelyEgyenleg();
	static void keszletFeltoltes();
};

