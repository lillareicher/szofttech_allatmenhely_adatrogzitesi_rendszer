#ifndef HIBA_H
#define HIBA_H

#include <iostream>

using namespace std;

class Hiba : public exception {
    string msg = "Rendszerhiba";
public:
    const char* what() const noexcept
    {
        return msg.c_str();
    }
};

#endif