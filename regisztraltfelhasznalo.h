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
    static bool allatSzabadKilistaz(const string& felhasznalonev);
    static void allatIdoPontFoglalas(const string& felhasznalonev);
    static void kervenyLeadas(const string& felhasznalonev);
    static void adomanyozasMenhelynek(const string& felhasznalonev);
    static void virtualisOrokbefogas(const string& felhasznalonev);


};

#endif // REGISZTRALTFELHASZNALO_H