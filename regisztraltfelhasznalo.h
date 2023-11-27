#ifndef REGISZTRALTFELHASZNALO_H
#define REGISZTRALTFELHASZNALO_H

#include "rang.h"
#include "felhasznalo.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

class RegisztraltFelhasznalo : public Felhasznalo
{
    Rang rang;
    static int rangSzamlalo;
public:
    RegisztraltFelhasznalo(Rang _rang, const string& _nev, const string& _jelszo);
    static void addFelhasznaloEgyenleg(const string& felhasznalonev);
    static void onkentesSzabadKilistaz();
    static void onkentesIdopontFoglalas(const string& felhasznalonev);
    static void allatokKilistaz();
    static void allatSzabadKilistaz();
    static void allatIdoPontFoglalas();
    static void kervenyLeadas(const string& felhasznalonev);
    static int getRangSzamlalo();
    static void setRangSzamlalo(int rsz);

};

#endif // REGISZTRALTFELHASZNALO_H