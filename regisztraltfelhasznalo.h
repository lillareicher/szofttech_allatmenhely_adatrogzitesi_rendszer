#ifndef REGISZTRALTFELHASZNALO_H
#define REGISZTRALTFELHASZNALO_H

#include "Rang.h"
#include "Egyenleg.h"
#include "felhasznalo.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

class RegisztraltFelhasznalo : public Felhasznalo
{
    Rang rang;
    static unsigned felhasznaloEgyenleg;
public:
    RegisztraltFelhasznalo(Rang _rang, const string& _nev, const string& _jelszo);
    static unsigned getFelhasznaloEgyenleg();
    static void addFelhasznaloEgyenleg(unsigned feltoltottEgyenleg);
    static void onkentesSzabadKilistaz();
    static void onkentesIdopontFoglalas(string felhasznalonev);
    static void allatokKilistaz();
    static void allatSzabadKilistaz();
    static void allatIdoPontFoglalas();

};

#endif // REGISZTRALTFELHASZNALO_H