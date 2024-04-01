#ifndef RANG_H
#define RANG_H

#include "rangtipus.h"
#include "hiba.h"
#include <fstream>
#include <sstream>

class Rang
{
    int rangID;
    static RangTipus tipus;
public:
    Rang(int _rangID);
    static void setTipus(int t);
    void setRangID(int r);
    int getRangID() const;
    static RangTipus getRangTipus();
    static void setRang(const string& felhasznalonev, int ujRang);
};

#endif // RANG_H
