#include "hiba.h"
#include "allatok.h"
#define _CRT_NO_SECURE_WARNINGS_GLOBAL

void Hiba::folyositasiHiba()
{
    ofstream outputFile("folyositasihiba.txt");

    if (outputFile.is_open())
    {
        string msg = "Hibas_tranzakcio";
        outputFile << msg << endl;
    }
    outputFile.close();
}

void Hiba::folyositasiHibaleiras()
{
    ifstream inputFile("folyositasihiba.txt");

    if (inputFile.is_open())
    {
        string msg;
        time_t raw_time;
        time(&raw_time);
        struct tm local_time;
        localtime_s(&local_time, &raw_time);
        inputFile >> msg;
        if (msg != "")
        {
            cout << "Rendszeruzenet: " << msg << ", idopont: " << put_time(&local_time, "%F %T") << endl;
        }
    }
    inputFile.close();
}

int Hiba::intBekerHiba()
{
    int input;
    bool validInput = false;

    while (!validInput) {
        if (cin >> input) {
            validInput = true;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nem szamot adott meg. Adjon meg helyes erteket: ";
        }
    }

    return input;
}

string Hiba::allatVanHiba()
{
    string input = "";
    bool van = false;

    while (!Allatok::allatVan(input) || !van) {
        cin >> input;
        if (Allatok::allatVan(input)) {
            van = true;
        }
        else {
            cout << "Nincs ilyen allat a menhelyen. Irjon be egy uj nevet: ";
            cin.clear();
        }
    }
    return input;
}
