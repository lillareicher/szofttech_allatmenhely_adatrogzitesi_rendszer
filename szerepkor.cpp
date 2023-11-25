#include "szerepkor.h"

Szerepkor::Szerepkor(int _ID): ID(_ID), tipus(SzerepkorTipusok::Regisztralt_Felhasznalo)
{
}

void Szerepkor::setSzerepkorTipusok(int sz)
{
	switch (sz)
	{
		case 0: tipus = SzerepkorTipusok::Admin;
			break;
		case 1: tipus = SzerepkorTipusok::Regisztralt_Felhasznalo;
			break;
		case 2: tipus = SzerepkorTipusok::Ugyintezo;
			break;
		case 3: tipus = SzerepkorTipusok::Alkalmazott;
			break;
		default : throw 0;
	}
}
