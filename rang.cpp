#include "rang.h"

Rang::Rang(int _rangID): rangID(_rangID), tipus(RangTipus::Kezdo)
{
}

void Rang::setTipus(int t)
{
	switch (t)
	{
	case 0: tipus = tipus = RangTipus::Kezdo;
		break;
	case 1: tipus = tipus = RangTipus::Kozepes;
		break;
	case 2: tipus = tipus = RangTipus::Halado;
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

RangTipus Rang::getRangTipus() const
{
	return tipus;
}
