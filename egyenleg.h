#ifndef EGYENLEG_H
#define EGYENLEG_H

#include "regisztraltfelhasznalo.h"
#include <string>
using namespace std;

class Egyenleg
{
    int egyenleg;
public:
    Egyenleg(unsigned _egyenleg);
    Egyenleg& operator+=(const Egyenleg& other);
    unsigned getEgyenleg() const;
    void setEgyenleg(unsigned ujegyenleg);
    static int getFelhasznaloEgyenleg(const string &felhasznalonev);
    static void setFelhasznaloEgyenleg(const string &felhasznalonev, unsigned ertek);

};

#endif // EGYENLEG_H
