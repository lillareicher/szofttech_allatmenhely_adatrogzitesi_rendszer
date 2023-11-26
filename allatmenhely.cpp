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

void AllatMenhely::visszaABeRegMenube() {
    cout << "Visszateres a bejelentkezes/regisztracio menube." << endl;
}


void AllatMenhely::kilepes() {
    cout << "Kilepes a programbol. Viszontlatasra!" << endl;
    visszaABeRegMenube();
}

void AllatMenhely::bejelentkezes() {
    string felhasznalonev;
    string jelszo;

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

    cout << endl;

    if (AllatMenhely::validBejelentkezes(felhasznalonev, jelszo)) {
        cout << "Bejelentkezes sikeres! Udv, " << felhasznalonev << "!" << endl;
    }
    else {
        cout << "Bejelentkezes sikertelen. Hibas felhasznalonev vagy jelszo." << endl;
    }
}

void AllatMenhely::regisztracio() {
    string felhasznalonev;
    string jelszo;

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

    cout << endl;

    AllatMenhely::regisztracio(felhasznalonev, jelszo);
}