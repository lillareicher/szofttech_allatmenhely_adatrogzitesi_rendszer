#pragma once

#include "regisztraltfelhasznalo.h"
#include "allatmenhely.h"
#include "egyenleg.h"
#include "rang.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Allatok {
public:
    Allatok(const string& _nev, int _kor, const string& _nem, const string& _kezelhetoseg, const string& _egeszsegugyiAllapot);
    string nev;
    int kor;
    string nem;
    string kezelhetoseg;
    string egeszsegugyiAllapot;
    static void addAllatEgyenleg(const string& allatnev, int ertek);
    static bool allatVan(const string& allat);
    static int getAllatRang(const string& allatnev);
    static void allatListazas();
};