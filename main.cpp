#include "rang.h"
#include "hiba.h"
#include "szerepkor.h"
#include <iostream>

#include <iostream>
#include <string>
#include <conio.h>

#include "allatmenhely.h"
#include "felhasznalo.h"
#include "adminisztrator.h"
#include "idopontok.h"
#include "regisztraltfelhasznalo.h"

void kilepes() {
    cout << "Kilepes a programbol. Viszontlatasra!" << endl;
}

int main() {
    string felhasznalonev;
    string jelszo;

    char valasztas;

    while (true) {
        cout << "Valassz egy opciot:\n";
        cout << "1. Bejelentkezes\n";
        cout << "2. Regisztracio\n";
        cout << "3. Kilepes\n";
        cin >> valasztas;

        cout << endl;

        switch (valasztas) {
        case '1': {
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
            break;
        }
        case '2': {
            AllatMenhely::regisztracio(felhasznalonev, jelszo);
            break;
        }
        case '3':
            kilepes();
            break;
        default:
            cout << "Hibas valasztas!" << endl;
            break;
        }

    }



    if (AllatMenhely::validBejelentkezes(felhasznalonev, jelszo) || valasztas == '2')
    {
        switch (Szerepkor::getSzerepkor(felhasznalonev))
        {
        case 0: Szerepkor::getSzerepkor(felhasznalonev) == 0;
        {
            char valasztas;
            cout << "\nValasszon az elerheto funckiok kozul: \n";
            cout << "1. Rangadas\n";
            cout << "2. Felhasznalok listazasa\n";
            cout << "3. Felhasznalo torlese\n";

            cin >> valasztas;
            /*switch (valasztas)
            {
                case 1: valasztas == '1';
                {
                    string felhasznalonev;
                    int ertek;
                    cout << "Kerem adja meg a felhasznalo nevet: ";
                    cin >> felhasznalonev;
                    cout << "Kerem adja meg a megadni kivant rang erteket (0 - kezdo, 1 - kozephalado, 2 - halado): ";
                    cin >> ertek;
                    Adminisztrator::rangAdas(felhasznalonev, ertek);
                }
                case 2: valasztas == '2';
                {
                    cout << "proba" << endl;
                }
            }*/
            if (valasztas == '1')
            {
                string felhasznalonev;
                int ertek;
                cout << "Kerem adja meg a felhasznalo nevet: ";
                cin >> felhasznalonev;
                cout << "Kerem adja meg a megadni kivant rang erteket (0 - kezdo, 1 - kozephalado, 2 - halado): ";
                cin >> ertek;
                Adminisztrator::rangAdas(felhasznalonev, ertek);
            }
            if (valasztas == '2')
            {
                Adminisztrator::felhasznaloListaz();
            }
            if (valasztas == '3')
            {
                string felhasznalonev;
                cout << "Kerem adja meg a torlesre kerulo felhasznalo nevet: ";
                cin >> felhasznalonev;
                Adminisztrator::felhasznaloTorles(felhasznalonev);
            }
        }
        break;

        case 1: Szerepkor::getSzerepkor(felhasznalonev) == 1;
        {
            char valasztas;
            cout << "\nValasszon az elerheto funckiok kozul: \n";
            cout << "1. Adomanyozas\n";
            cout << "2. Virtualis adomanyozas\n";
            cin >> valasztas;
        }
        break;
        case 2: Szerepkor::getSzerepkor(felhasznalonev) == 2;
        {
            char valasztas;
            cout << "\nValasszon az elerheto funckiok kozul: \n";
            cout << "1. Uj idopont hozzadasa\n";
            cout << "2. Keszlet feltoltese\n";
            cin >> valasztas;
        }
        case 3: Szerepkor::getSzerepkor(felhasznalonev) == 3;
        {
            char valasztas;
            cout << "\nValasszon az elerheto funckiok kozul: \n";
            cout << "1. Allat adatainak feltoltese\n";
            cout << "2. Felhasznalo figyelmeztetese\n";
            cin >> valasztas;
        }
        }
    }




    //Szabad idõpontok kilistázása
    //{
    //    RegisztraltFelhasznalo::onkentesSzabadKilistaz();
    //}

    //Önkéntes idõpontfoglalás 
    //cout << "Valasszon az alabbi lehetosegek kozul:" << endl;
    //cout << "1. Onkentes idopont foglalas" << endl;
    //cout << "2. Kilepes" << endl;
    //cin >> choice;

    //{
    //    if (choice == '1') {
    //        RegisztraltFelhasznalo regFelhasznalok;
    //        Felhasznalo felhasznalo = regFelhasznalok.felhasznaloBeolvasas("users.txt");

    //        RegisztraltFelhasznalo::onkentesIdopontFoglalas(felhasznalo);
    //    }
    //    else {
    //        cout << "Sikertelen." << endl;
    //    }
    //    if (choice == '2') {
    //        //cout << "Kilepes" << endl;
    //        return 0;
    //    }

    //}

    return 0;
}