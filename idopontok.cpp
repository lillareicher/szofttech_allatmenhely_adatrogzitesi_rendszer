#include "idopontok.h"

Idopontok::Idopontok() {
	szabadIdopontok = { "2023-01-01 10:00", "2023-01-02 14:00", "2023-01-03 12:00" };
}

Idopontok::Idopontok(int _ev, int _honap, int _nap, int _ora) : 
	ev(_ev),
	honap(_honap),
	nap(_nap),
	ora(_ora)
{}
int Idopontok::getDatum() const{
	return ev, honap, nap, ora;
}


