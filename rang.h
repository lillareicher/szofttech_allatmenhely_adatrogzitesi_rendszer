#ifndef RANG_H
#define RANG_H

#include "rangtipus.h"

class Rang
{
    int rangID;
    RangTipus tipus;
public:
    Rang(int _rangID);
    void setTipus(int t);
    void setRangID(int r);
    int getRangID() const;
    RangTipus getRangTipus() const;
};

#endif // RANG_H
