#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "felhasznalo.h"
#include "kervenyek.h"

using namespace std;

class Ugyintezo : public Felhasznalo
{
    static int menhelyEgyenleg;
public:
    Ugyintezo() = default;
    static void kervenyListazas();
    static void kervenyElfogadas();
    static void kervenyElutasitas();
    static void addSetaltatasIdopont();
    static void addOnkentesIdopont();
    static void setaltatasokListazas();
    static void onkenteskedesListazas();
    static void setMenhelyEgyenleg();
    static void keszletFeltoltes();
};