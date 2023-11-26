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
    Egyenleg felhasznaloEgyenleg;
public:
    RegisztraltFelhasznalo(Rang _rang, Egyenleg _felhasznaloEgyenleg, const string& _nev, const string& _jelszo);
    Egyenleg getFelhasznaloEgyenleg() const;
    void addFelhasznaloEgyenleg(const Egyenleg& feltoltottEgyenleg);
    static void onkentesSzabadKilistaz();
    static void onkentesIdopontFoglalas(string felhasznalonev);
    static void allatokKilistaz();
    static void allatSzabadKilistaz();
    static void allatIdoPontFoglalas();

};

#endif // REGISZTRALTFELHASZNALO_H