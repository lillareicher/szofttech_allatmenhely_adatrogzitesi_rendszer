#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "allatmenhely.h"

using namespace std;

// Fájl elérési útja, ahol a felhasználónevek és jelszavak tárolva vannak
const char* FILE_PATH = "felhasznalok.txt";

// Funkció a felhasználók ellenõrzésére
bool AllatMenhely::validBejelentkezes(const string& felhasznalonev, const string& jelszo) {
    ifstream file(FILE_PATH);

    if (!file.is_open()) {
        cerr << "A fajl nem nyithato meg: " << FILE_PATH << endl;
        return false;
    }

    string storedUsername;
    string storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == felhasznalonev && storedPassword == jelszo) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Funkció a felhasználók regisztrációjára
void AllatMenhely::regisztracio(const string& felhasznalonev, const string& jelszo) 
{
    ofstream file(FILE_PATH, ios::app);

    if (!file.is_open()) {
        cerr << "A fajl nem nyithato meg: " << FILE_PATH << endl;
        return;
    }
    
    file << felhasznalonev << " " << jelszo << " " <<  1 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
    file.close();

    cout << "\nRegisztracio sikeres! Udv, " << felhasznalonev << "! Kerem jelentkezzen be!\n" << endl;
}


void AllatMenhely::visszaLep()
{

}


string AllatMenhely::belepes()
{
    string felhasznalonev = "";
    string jelszo = "";
    cout << "Felhasznalonev: ";
    cin >> felhasznalonev;

    cout << "Jelszo: ";

    char ch;
    while ((ch = _getch()) != 13) {
        if (ch == '\b') {
            if (!jelszo.empty()) {
                jelszo.pop_back();
                cout << "\b \b";
            }
        }
        else {
            jelszo.push_back(ch);
            cout << '*';
        }
    }
    if (AllatMenhely::validBejelentkezes(felhasznalonev, jelszo)) {
        cout << "\nBejelentkezes sikeres! Udv, " << felhasznalonev << "!" << endl;
        _getch();
        return felhasznalonev;
        system("cls");

    }
    if(!(AllatMenhely::validBejelentkezes(felhasznalonev, jelszo)))
    {
        cout << "\nBejelentkezes sikertelen. Hibas felhasznalonev vagy jelszo.\n" << endl;
        _getch();
        system("cls");

    }
    return "";
}

bool AllatMenhely::ellenorizFoglaltFelhasznalonev(const string& felhasznalonev) {
    ifstream file(FILE_PATH);
    if (!file.is_open()) {
        cerr << "A fajl nem nyithato meg: " << FILE_PATH << endl;
        return true;
    }

    string felhasznaloNev;

    cout << endl;

    while (file >> felhasznaloNev) {
        if (felhasznaloNev == felhasznalonev) {
            cout << "Hiba: A felhasznalonev mar foglalt. Visszateres a menube.\n" << endl;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


void AllatMenhely::kijelentkezes() 
{
    system("cls");
}
