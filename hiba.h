#ifndef HIBA_H
#define HIBA_H

#include <iostream>
#include <ctime>

using namespace std;

class Hiba : public exception {
    string leiras = "Hiba!";
    time_t most = time(0);
    char *datum= ctime(&most);
public:
    const char* what() const noexcept
    {
        return leiras.c_str();
    }
};

#endif