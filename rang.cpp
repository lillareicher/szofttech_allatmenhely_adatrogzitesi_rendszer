#include "rang.h"

RangTipus Rang::tipus = RangTipus::Kezdo;

Rang::Rang(int _rangID): rangID(_rangID)
{
}

void Rang::setTipus(int t)
{
	switch (t)
	{
	case 0: tipus = RangTipus::Kezdo;
		break;
	case 1: tipus = RangTipus::Kozep;
		break;
	case 2: tipus = RangTipus::Halado;
		break;
	default: throw Hiba();
	}
}

void Rang::setRangID(int r)
{
	rangID = r;
}

int Rang::getRangID() const
{
	return rangID;
}

RangTipus Rang::getRangTipus()
{
	return tipus;
}


