#include "kervenyek.h"


Kervenyek::Kervenyek(const string& _kerveny, const string& _kervenyTargy) :
    kerveny(_kerveny), kervenyTargy(_kervenyTargy) // 2023.12.01. modositva
{

}

int Kervenyek::getUtolsoID()
{
    int utolso = 0;
    Kervenyek uj("", "");
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            int id;
            string targy, kerveny, fnev;
            bool elfogadva;
            inputFile >> targy >> kerveny >> fnev >> elfogadva >> id;
            if (targy != "" && id > utolso) {
                utolso = id;
            }
        }
        inputFile.close();
    }
    return utolso;
}