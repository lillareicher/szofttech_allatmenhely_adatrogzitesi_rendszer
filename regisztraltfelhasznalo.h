#pragma once

#include "rang.h"
#include "egyenleg.h"
#include "felhasznalo.h"

using namespace std;

class RegisztraltFelhasznalo : public Felhasznalo
{
    Rang rang;
    Egyenleg felhasznaloEgyenleg;

public:
    RegisztraltFelhasznalo();
    RegisztraltFelhasznalo(Rang _rang, Egyenleg _felhasznaloEgyenleg, int _szerepkorID, const string& _nev, const string& _jelszo);
    Egyenleg getFelhasznaloEgyenleg() const;
    void addFelhasznaloEgyenleg(const Egyenleg& feltoltottEgyenleg);
    //static void onkentesSzabadKilistaz();
    Felhasznalo felhasznaloBeolvasas(const std::string& fajlnev);
    static void onkentesIdopontFoglalas(const Felhasznalo& felhasznalo);
};
