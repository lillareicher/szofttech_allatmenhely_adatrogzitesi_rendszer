#include "egyenleg.h"

Egyenleg::Egyenleg(): egyenleg(0)
{

}

Egyenleg& Egyenleg::operator+=(const Egyenleg& other)
{
	// TODO: insert return statement here
}

unsigned Egyenleg::getEgyenleg() const
{
	return egyenleg;
}

void Egyenleg::setEgyenleg(unsigned ujegyenleg)
{
	egyenleg = ujegyenleg;
}


