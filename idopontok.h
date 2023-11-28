#pragma once
#include <string>
using namespace std;

class Idopontok {
public:
    int ev;
    int honap;
    int nap;
    int ora;
    Idopontok(int _ev, int _honap, int _nap, int _ora);
    static bool validEv(int ev);
    static bool validHonap(int honap);
    static bool validNap(int nap);
    static bool validOra(int ora);
    static bool validDatum(int ev, int honap, int nap, int ora);
};