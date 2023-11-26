#pragma once
#include "felhasznalo.h"

class Ugyintezo : public Felhasznalo {
private:
	//Egyenleg menhelyEgyenleg;
public:
	bool kervenyElfogadas();
	void addIdopont();
	int getMenhelyEgyenleg() const;
	//void setMenhelyEgyenleg(Egyenleg& menhelyEgyenleg);
	void keszletFeltoltes();
};