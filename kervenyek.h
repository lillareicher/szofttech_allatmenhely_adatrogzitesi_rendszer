#ifndef KERVENYEK_H
#define KERVENYEK_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Kervenyek
{

public:
    Kervenyek(const string& _kerveny, const string& _kervenyTargy); // 2023.12.01. modositva
    string kerveny;
    string kervenyTargy;
    static int getUtolsoID();
};

#endif // KERVENYEK_H
