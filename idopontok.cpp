#include "idopontok.h"

Idopontok::Idopontok(int _ev, int _honap, int _nap, int _ora) :
    ev(_ev),
    honap(_honap),
    nap(_nap),
    ora(_ora)
{}

bool Idopontok::validEv(int ev)
{
    if (ev > 2022 && ev < 2031) return true;
    return false;
}

bool Idopontok::validHonap(int honap)
{
    if (honap < 13 && honap > 0) return true;
    return false;
}

bool Idopontok::validNap(int nap)
{
    if (nap > 0 && nap < 32) return true;
    return false;
}

bool Idopontok::validOra(int ora)
{
    if (ora >= 0 && ora < 25) return true;
    return false;
}

bool Idopontok::validDatum(int ev, int honap, int nap, int ora)
{
    if (validEv(ev) == true && validHonap(honap) == true && validNap(nap) == true && validOra(ora) == true) return true;
    return false;
}