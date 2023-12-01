#include "kervenyek.h"

int Kervenyek::id = -1;

Kervenyek::Kervenyek(const string& _kerveny, const string& _kervenyTargy) :
    kerveny(_kerveny), kervenyTargy(_kervenyTargy) // 2023.12.01. modositva
{

}

int Kervenyek::getId()
{
    return id++;
}
