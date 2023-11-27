#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h> 

#include "allatmenhely.h"
#include "felhasznalo.h"
#include "adminisztrator.h"
#include "idopontok.h"
#include "regisztraltfelhasznalo.h"
#include "rang.h"
#include "hiba.h"
#include "szerepkor.h"
#include "ertesites.h"

using namespace std;

int main() {

    

    bool kilep = false;
    
    do {
        string felhasznalonev;
        string jelszo;
        char valasztas;

        cout << "Valassz egy opciot:\n";
        cout << "1. Bejelentkezes\n";
        cout << "2. Regisztracio\n";
        cout << "3. Kilepes a programbol\n";
        cin >> valasztas;

        if (valasztas == '1')
        {
            bool vege = false;
            felhasznalonev = AllatMenhely::belepes();
            switch (Szerepkor::getSzerepkor(felhasznalonev))
            {
            case 0:
            {
                do{
                char valasztas;
                cout << "\nValasszon az elerheto funckiok kozul: \n";
                cout << "1. Rangadas\n";
                cout << "2. Felhasznalok listazasa\n";
                cout << "3. Felhasznalo torlese\n";
                cout << "4. Kerveny felulvizsgalata\n";
                cout << "5. Kijelentkezes\n";

                cin >> valasztas;

                if (valasztas == '1')
                {
                    string felhasznalonev;
                    int ertek;
                    cout << "\nKerem adja meg a felhasznalo nevet: ";
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
                    Adminisztrator::felhasznaloTorles();
                }
                if (valasztas == '4')
                {
                    string targy;
                    cout << "\nKerem adja meg a felulvizsgalni kivant kerveny targyat: ";
                    cin >> targy;
                    Adminisztrator::kervenyFelulvizsgalat(targy);
                }

                if (valasztas == '5')
                {
                    vege = true;
                    system("cls");
                }

                } while (!vege);
            }
            break;

            case 1:
            {
                do {
                    char valasztas;
                    system("cls");
                    cout << "Valasszon az elerheto funckiok kozul: \n";
                    cout << "1. Egyenleg feltoltese\n";
                    cout << "2. Adomanyozas\n";
                    cout << "3. Virtualis adomanyozas\n";
                    cout << "4. Idopontfoglalas\n";
                    cout << "5. Orokbefogadasi kerveny leadasa\n";
                    cout << "6. Kijelentkezes\n";

                    cin >> valasztas;


                    if (valasztas == '1')
                    {
                        system("cls");
                        RegisztraltFelhasznalo::addFelhasznaloEgyenleg(felhasznalonev);
                    }

                    if (valasztas == '2')
                    {
                        system("cls");
                        cout << "Teszt" << endl;
                    }

                    if (valasztas == '3')
                    {
                        system("cls");
                        cout << "Teszt" << endl;
                    }

                    if (valasztas == '4')
                    {
                        system("cls");
                        char segitovalaszt;
                        cout << "\nValasszon az alabbi opciok kozul: \n";
                        cout << "1. Kutyasetaltatas\n";
                        cout << "2. Onkenteskedes\n";
                        cin >> segitovalaszt;
                        if (segitovalaszt == '1')
                        {
                            RegisztraltFelhasznalo::allatIdoPontFoglalas();
                        }
                        if (segitovalaszt == '2')
                        {
                            RegisztraltFelhasznalo::onkentesIdopontFoglalas(felhasznalonev);
                            
                        }
                        
                        /*else
                        {
                            cout << "Hiba!" << endl;
                        }*/
                    }

                    if (valasztas == '5')
                    {
                        system("cls");
                        cout << "Teszt" << endl;
                    }

                    if (valasztas == '6')
                    {
                        vege = true;
                        system("cls");

                    }

                    else
                    {
                        cout << "Hiba!" << endl;
                    }
                    

                } while (!vege);
                break;

            case 2:
            {
                do{
                char valasztas;
                system("cls");
                cout << "\nValasszon az elerheto funckiok kozul: \n";
                cout << "1. Idopont hozzadasa\n";
                cout << "2. Kerveny elfogadasa\n";
                cout << "3. Menhely egyenlegenek feltoltese\n";
                cout << "4. Keszletfeltoltes kezdemenyezese\n";
                cout << "5. Kijelentkezes\n";
                cin >> valasztas;

                if (valasztas == '1')
                {
                    system("cls");
                    cout << "Teszt" << endl;
                }

                if (valasztas == '2')
                {
                    system("cls");
                    cout << "Teszt" << endl;
                }

                if (valasztas == '3')
                {
                    system("cls");
                    cout << "Teszt" << endl;
                }

                if (valasztas == '4')
                {
                    system("cls");
                    cout << "Teszt" << endl;
                }

                if (valasztas == '5')
                {
                    vege = true;
                    system("cls");
                }

                else
                {
                    cout << "Hiba!" << endl;
                }
                } while (!vege);
            } 
            break;

            case 3:
            {
                do{
                char valasztas;
                system("cls");
                cout << "\nValasszon az elerheto funckiok kozul: \n";
                cout << "1. Allat adatainak feltoltese\n";
                cout << "2. Felhasznalo figyelmeztetese\n";
                cout << "3. Keszletfeltoltes igenylese\n";
                cout << "4. Felhasznalo rangpontjainak novelese\n";
                cout << "5. Kijelentkezes\n";
                cin >> valasztas;

                if (valasztas == '1')
                {
                    cout << "Teszt" << endl;
                }

                if (valasztas == '2')
                {
                    cout << "Teszt" << endl;
                }

                if (valasztas == '3')
                {
                    cout << "Teszt" << endl;
                }

                if (valasztas == '4')
                {
                    cout << "Teszt" << endl;
                }

                if (valasztas == '5')
                {
                    vege = true;
                    system("cls");
                }

                else
                {
                    cout << "Hiba!" << endl;
                }
                } while (!vege);

            }
            break;

            default: Szerepkor::getSzerepkor(felhasznalonev);
            {
                cout << "\nValasszon az elerheto funkciok kozul: ";
                cout << "1. Bejelentkezes\n";
                cout << "2. Regisztracio\n";
            }
            break;
            }
            }
        }

            if (valasztas == '2')
            {
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
                AllatMenhely::regisztracio(felhasznalonev, jelszo);
            }

            if (valasztas == '3')
            {
                kilep = true;
            }



            /*   if (valasztas != 1 && valasztas != 2) ?? miert nem mukodik ??
               {
                   cout << "Hiba!" << endl;
               }*/
        }while (!kilep);
        return  0;
}


