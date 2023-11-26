#ifndef REGISZTRALTFELHASZNALO_H
#define REGISZTRALTFELHASZNALO_H

#include "Rang.h"
#include "felhasznalo.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

class RegisztraltFelhasznalo : public Felhasznalo
{
    Rang rang;
public:
    RegisztraltFelhasznalo(Rang _rang, const string& _nev, const string& _jelszo);
    static void addFelhasznaloEgyenleg(const string &felhasznalonev);
    static void onkentesSzabadKilistaz();
    static void onkentesIdopontFoglalas(const string& felhasznalonev);
    static void allatokKilistaz();
    static void allatSzabadKilistaz();
    static void allatIdoPontFoglalas();

};

#endif // REGISZTRALTFELHASZNALO_H
