#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "allatmenhely.h"

using namespace std;

// Fájl elérési útja, ahol a felhasználónevek és jelszavak tárolva vannak
const char* FILE_PATH = "users.txt";

// Funkció a felhasználók ellenõrzésére
bool AllatMenhely:: validBejelentkezes(const string& felhasznalonev, const string& jelszo) {
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
void AllatMenhely::regisztracio(const string& felhasznalonev, const string& jelszo) {
    ofstream file(FILE_PATH, ios::app); 

    if (!file.is_open()) {
        cerr << "A fajl nem nyithato meg: " << FILE_PATH << endl;
        return;
    }

    file << felhasznalonev << " " << jelszo << endl;
    file.close();

    cout << "Regisztracio sikeres! Udv, " << felhasznalonev << "!" << endl;
}
