#include <iostream>
#include <string>
#include <conio.h>

#include "allatmenhely.h"
#include "felhasznalo.h"
#include "adminisztrator.h"
#include "idopontok.h"
#include "regisztraltfelhasznalo.h"

using namespace std;

int main() {
    string felhasznalonev;
    string jelszo;

    char choice;

    cout << "Valassz egy opciot:\n";
    cout << "1. Bejelentkezes\n";
    cout << "2. Regisztracio\n";
    cin >> choice;

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

    if (choice == '1') {
        if (AllatMenhely::validBejelentkezes(felhasznalonev, jelszo)) {
            cout << "Bejelentkezes sikeres! Udv, " << felhasznalonev << "!" << endl;
        }
        else {
            cout << "Bejelentkezes sikertelen. Hibas felhasznalonev vagy jelszo." << endl;
        }
    }
    else if (choice == '2') {
        AllatMenhely::regisztracio(felhasznalonev, jelszo);
    }
    else {
        cout << "Hiba!" << endl;
    }

    //Adminisztrátor felhasználó törlése
    /*{
        string filename = "users.txt";
        int targetId;

        cout << "Irja be a torolni kivant felhasznalo id-jat! ";
        cin >> targetId;

        if (Adminisztrator::felhasznaloTorles(filename, targetId)) {
            cout << "Torles sikeres." << endl;
        }
        else {
            cerr << "Torles sikertelen." << endl;
        }
    }*/

    //Szabad idõpontok kilistázása
    //{
    //    RegisztraltFelhasznalo::onkentesSzabadKilistaz();
    //}

    //Önkéntes idõpontfoglalás 
    cout << "Valasszon az alabbi lehetosegek kozul:" << endl;
    cout << "1. Onkentes idopont foglalas" << endl;
    cout << "2. Kilepes" << endl;
    cin >> choice;

    {
        if (choice == '1') {
            RegisztraltFelhasznalo regFelhasznalok;
            Felhasznalo felhasznalo = regFelhasznalok.felhasznaloBeolvasas("users.txt");

            RegisztraltFelhasznalo::onkentesIdopontFoglalas(felhasznalo);
        }
        else {
            cout << "Sikertelen." << endl;
        }
        if (choice == '2') {
            //cout << "Kilepes" << endl;
            return 0;
        }

    }

    return 0;
}
