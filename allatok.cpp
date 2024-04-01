#include "allatok.h"




Allatok::Allatok(const string& _nev, int _kor, const string& _nem, const string& _kezelhetoseg, const string& _egeszsegugyiAllapot) :
    nev(_nev), kor(_kor), nem(_nem), kezelhetoseg(_kezelhetoseg), egeszsegugyiAllapot(_egeszsegugyiAllapot)
{

}



void Allatok::addAllatEgyenleg(const string& allatnev, int ertek)
{
    ifstream inputFile("allatok.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (outPutFile.is_open() && inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if (nev != "") {
                if (allatnev == nev) {
                    outPutFile << nev << " " << eletkor << " " << nem << " " << allatrang << " " << allapot << " " << allatEgyenleg + ertek << endl;
                }
                else {
                    outPutFile << nev << " " << eletkor << " " << nem << " " << allatrang << " " << allapot << " " << allatEgyenleg << endl;
                }
            }

        }
        inputFile.close();
        remove("allatok.txt");
        outPutFile.close();
        rename("temp.txt", "allatok.txt");
    }
}

bool Allatok::allatVan(const string& allat)
{
    bool talalt = 0;
    ifstream inputFile("allatok.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if (nev == allat) {
                talalt = 1;
            }
        }
        inputFile.close();
    }
    return talalt;
}

int Allatok::getAllatRang(const string& allatnev)
{
    ifstream inputFile("allatok.txt");
    int allatr = -1;
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if (nev == allatnev) {
                allatr = allatrang;
            }
        }
        inputFile.close();
    }
    return allatr;
}

void Allatok::allatListazas()
{
    ifstream inputFile("allatok.txt");

    cout << "Allatok adatainak listazasa: \n" << endl;

    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if(nev!="")
            { 
                cout << "Allat neve: " << nev << ", Kora: " << eletkor << ", Neme: " << nem << ", Kezelhetosege: ";
                switch (allatrang)
                {
                case 0:
                    cout << "Konnyu, ";
                case 1:
                    cout << "Kozepes, ";
                case 2:
                    cout << "Nehez, ";
                }
                cout << "Egeszsegugyi allapota: " << allapot << ", Egyenlege: " << allatEgyenleg << endl;
                }
        }
        inputFile.close();
    }
}
