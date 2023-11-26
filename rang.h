#pragma once

#include "rangtipus.h"
#include "hiba.h"

class Rang
{
    int rangID;
    RangTipus tipus;
public:
    Rang() = default;
    Rang(int _rangID);
    void setTipus(int t);
    void setRangID(int r);
    int getRangID() const;
    RangTipus getRangTipus() const;
};
