#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h> 
#include <windows.h>

#include "allatmenhely.h"
#include "felhasznalo.h"
#include "adminisztrator.h"
#include "idopontok.h"
#include "regisztraltfelhasznalo.h"
#include "rang.h"
#include "hiba.h"
#include "szerepkor.h"
#include "ugyintezo.h"
#include "alkalmazott.h"

using namespace std;

int main() {

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); 

    MoveWindow(console, r.left, r.top, 1200, 700, TRUE); // 1200 szeles, 700 magas

    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
    posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

    MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE); // kozepre helyezes

    bool kilep = false;
    
    do {
        string felhasznalonev;
        string jelszo;

        cout << "Udvozoljuk a menhely rendszereben!\nKerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";
        cout << "\n1. Bejelentkezes\n";
        cout << "2. Regisztracio\n";
        cout << "3. Kilepes a programbol\n";
        cout << endl;
        int valasztas = Hiba::intBekerHiba();

        if (valasztas == 1)
        {
            bool vege = false;
            /*felhasznalonev = AllatMenhely::belepes();*/

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
                system("cls");

            }
            if (!(AllatMenhely::validBejelentkezes(felhasznalonev, jelszo)))
            {
                cout << "\nBejelentkezes sikertelen. Hibasan megadott felhasznalonev vagy jelszo, probalja ujra!\n" << endl;
                _getch();
                system("cls");

            }

            system("cls");

            if(AllatMenhely::validBejelentkezes(felhasznalonev, jelszo))
            {
                switch (Szerepkor::getSzerepkor(felhasznalonev))
                {
                case 0:
                {
                    do{
                    system("cls");
                    cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";
                    cout << "\n1. Felhasznalok listazasa\n";
                    cout << "2. Felhasznalo torlese\n";
                    cout << "3. Kerveny felulvizsgalata\n";
                    cout << "4. Rangadas\n";
                    cout << "5. Szerepkor beallitasa\n";
                    cout << "6. Kijelentkezes\n";


                    int valasztas = Hiba::intBekerHiba();
                    cout << endl;

                    if (valasztas == 1)
                    {
                        system("cls");
                        Adminisztrator::felhasznaloListaz();
                        _getch();
                    }

                    if (valasztas == 2)
                    {
                        system("cls");
                        Adminisztrator::felhasznaloTorles(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == 3)
                    {
                        system("cls");
                        Ugyintezo::kervenyListazas();
                        cout << "\nKerem adja meg a felulvizsgalni kivant kerveny azonositojat: ";
                        int testid = Hiba::intBekerHiba();
                        Adminisztrator::kervenyFelulvizsgalat(testid);
                        _getch();
                    }

                    if (valasztas == 4)
                    {
                        system("cls");
                        Adminisztrator::felhasznaloListaz();
                        string fnev;
                        int ertek;

                        cout << "\nKerem adja meg a valasztott felhasznalo nevet: ";
                        cin >> fnev;
                        cout << "Kerem adja meg a megadni kivant rang erteket (0 - kezdo, 1 - kozephalado, 2 - halado): ";
                        cin >> ertek;

                        cout << endl;
                        Adminisztrator::rangAdas(fnev, ertek);
                        _getch();

                    }

                    if (valasztas == 5)
                    {
                        system("cls");
                        Adminisztrator::felhasznaloListaz();
                        string fnev;
                        int ertek;

                        cout << "\nKerem adja meg a valasztott felhasznalo nevet: ";
                        cin >> fnev;
                        cout << "\nKerem adja meg a beallitani kivant szerepkor erteket (1 - regisztralt felhasznalo, 2 - ugyintezo, 3 - alkalmazott): ";
                        cin >> ertek;

                        cout << endl;
                        Adminisztrator::szerepkorAdas(fnev, ertek);
                        _getch();
                    }
                

                    if (valasztas == 6)
                    {
                        system("cls");
                        vege = true;
                        AllatMenhely::kijelentkezes();
                    }   

                    } while (!vege);
                }
                break;

                case 1:
                {
                    do {
                        system("cls");
                        cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";
                        cout << "\n1. Egyenleg feltoltese\n";
                        cout << "2. Adomanyozas\n";
                        cout << "3. Virtualis orokbefogadas\n";
                        cout << "4. Idopontfoglalas\n";
                        cout << "5. Orokbefogadasi kerveny leadasa\n";
                        cout << "6. Ertesitesek megtekintese\n";
                        cout << "7. Kijelentkezes\n";

                        int valasztas = Hiba::intBekerHiba();
                        cout << endl;

                        if (valasztas == 1)
                        {
                            system("cls");
                            RegisztraltFelhasznalo::addFelhasznaloEgyenleg(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 2)
                        {
                            system("cls");
                            RegisztraltFelhasznalo::adomanyozasMenhelynek(felhasznalonev);
                            _getch();

                        }

                        if (valasztas == 3)
                        {
                            system("cls");
                            RegisztraltFelhasznalo::virtualisOrokbefogas(felhasznalonev);
                            _getch();

                        }

                        if (valasztas == 4)
                        {
                            bool segitovege = false;
                            do{
                            
                                system("cls");
                                cout << "Valasszon az alabbi opciok kozul: \n";
                                cout << "1. Kutyasetaltatas\n";
                                cout << "2. Onkenteskedes\n";
                                cout << "3. Visszalepes\n";
                                int segitovalaszt = Hiba::intBekerHiba();


                                if (segitovalaszt == 1)
                                {
                                    system("cls");
                                    RegisztraltFelhasznalo::allatIdoPontFoglalas(felhasznalonev);
                                    _getch();
                                }
                                if (segitovalaszt == 2)
                                {
                                    system("cls");
                                    RegisztraltFelhasznalo::onkentesIdopontFoglalas(felhasznalonev);
                                    _getch();
                            
                                }
                                if (segitovalaszt == 3)
                                {
                                    system("cls");
                                    segitovege = true;   
                                }
                        
                                else
                                {
                                    Hiba();
                                }
                            } while (!segitovege);
                        }

                        if (valasztas == 5)
                        {
                            system("cls");
                            RegisztraltFelhasznalo::kervenyLeadas(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 6)
                        {
                            system("cls");
                            cout << "A on szamara beerkezett ertesitesek listaja: " << endl;
                            Ertesitesek::ertesitesLekeres(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 7)
                        {
                            vege = true;
                            AllatMenhely::kijelentkezes();
                        }

                        else
                        {
                            Hiba();
                        }                   

                    } while (!vege);
                    break;

                case 2:
                {
                    do{                
                        system("cls");
                        cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";

                        cout << "\n1. Idopontok letrehozasa\n";
                        cout << "2. Idopontok listazasa\n";
                        cout << "3. Felhasznalo ertesitese\n";               
                        cout << "4. Menhely egyenlegenek feltoltese\n";
                        cout << "5. Keszletfeltoltes kezdemenyezese\n";
                        cout << "6. Ertesitesek megtekintese\n";
                        cout << "7. Kervenyek listazasa\n";
                        cout << "8. Kerveny elfogadasa\n";
                        cout << "9. Kerveny elutasitasa\n";
                        cout << "10. Kijelentkezes\n";

                        int valasztas = Hiba::intBekerHiba();
                        cout << endl;

                        if (valasztas == 1)
                        {
                            system("cls");
                            bool segitovege = false;
                            do {

                                system("cls");
                                cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";
                                cout << "\n1. Kutyasetaltatas tipusu idopont letrehozasa\n";
                                cout << "2. Onkenteskedes tipusu idopont letrehozasa\n";
                                cout << "3. Visszalepes\n";
                                int segitovalaszt = Hiba::intBekerHiba();

                        
                                if (segitovalaszt == 1)
                                {
                                    system("cls");
                                    Ugyintezo::addSetaltatasIdopont();
                                    _getch();   
                                }

                                if (segitovalaszt == 2)
                                {
                                    system("cls");
                                    Ugyintezo::addOnkentesIdopont();
                                    _getch();
                                }
                                if (segitovalaszt == 3)
                                {
                                    system("cls");
                                    segitovege = true;
                                }

                                else
                                {
                                    Hiba();
                                }
                            } while (!segitovege);

                        }

                        if (valasztas == 2)
                        {
                            system("cls");
                            bool segitovege = false;
                            do {

                                system("cls");
                                cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";
                                cout << "\n1. Kutyasetaltatas tipusu idopontok listazasa\n";
                                cout << "2. Onkenteskedes tipusu idopontok listazasa\n";
                                cout << "3. Visszalepes\n";
                                int segitovalaszt = Hiba::intBekerHiba();


                                if (segitovalaszt == 1)
                                {
                                    system("cls");
                                    Ugyintezo::setaltatasokListazas();
                                    _getch();
                                }

                                if (segitovalaszt == 2)
                                {
                                    system("cls");
                                    Ugyintezo::onkenteskedesListazas();
                                    _getch();
                                }
                                if (segitovalaszt == 3)
                                {
                                    system("cls");
                                    segitovege = true;
                                }

                                else
                                {
                                    Hiba();
                                }
                            } while (!segitovege);

                        }

                        if (valasztas == 3)
                        {
                            system("cls");
                            Alkalmazott::felhasznaloListaz();
                            string fnev, targy, uzenet;
                            cout << "\nKerem, szokoz helyett alsovonast (_) hasznaljon!\n" << endl;
                            cout << "\nHa nem szeretne senkinek ertesitest kuldeni, irjon be egy nullat (0)!" << endl;
                            cout << "Kerem valasszon a megadott felhasznalok kozul, es irja be a nevet: ";
                            cin >> fnev;
                            if (fnev == "0")
                            {
                                cout << "Ertesites megszakitva!" << endl;
                            }
                            else
                            {
                                cout << "Kerem adja meg az ertesites targyat: ";
                                cin >> targy;
                                cout << "Kerem irja be az ertesites uzenetet: ";
                                cin >> uzenet;

                                Ertesitesek::ertesites(fnev, targy, uzenet+"_Kuldo:_" + felhasznalonev + "_nevu_ugyintezo.", " "+felhasznalonev);
                            }
                            _getch();
                        }

                        if (valasztas == 4)
                        {
                            system("cls");
                            Ugyintezo::setMenhelyEgyenleg();
                            _getch();
                        }

                        if (valasztas == 5)
                        {
                            system("cls");
                            Ugyintezo::keszletFeltoltes();
                            _getch();
                        }

                        if (valasztas == 6)
                        {
                            system("cls");
                            cout << "A on szamara beerkezett ertesitesek listaja: " << endl;
                            Ertesitesek::ertesitesLekeres(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 7)
                        {
                            system("cls");
                            Ugyintezo::kervenyListazas();
                            _getch();
                        }

                        if (valasztas == 8)
                        {
                            system("cls");
                            Ugyintezo::kervenyElfogadas(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 9)
                        {
                            system("cls");
                            Ugyintezo::kervenyElutasitas(felhasznalonev);
                            _getch();
                        }

                        if (valasztas == 10)
                        {
                            vege = true;
                            AllatMenhely::kijelentkezes();
                        }

                    } while (!vege);
                } 
                break;

                case 3:
                {
                    do{
                    system("cls");
                    cout << "Kerem valasszon az alabbi rendelkezesre allo opciok kozul: \n";

                    cout << "\n1. Allatok adatainak listazasa\n";
                    cout << "2. Allatok adatainak feltoltese\n";
                    cout << "3. Felhasznalo ertesitese\n";
                    cout << "4. Figyelmeztetes kiadasa\n";
                    cout << "5. Keszletfeltoltesi igeny benyujtasa\n";
                    cout << "6. Felhasznalo rangpontjainak novelese\n";
                    cout << "7. Ertesitesek megtekintese\n";
                    cout << "8. Kijelentkezes\n";
                    int valasztas = Hiba::intBekerHiba();
                    cout << endl;

                    if (valasztas == 1)
                    {
                        system("cls");
                        Allatok::allatListazas();
                        _getch();
                    }

                    if (valasztas == 2)
                    {
                        system("cls");
                        Alkalmazott::allatAdatFeltoltes();
                        _getch();
                    }

                    if (valasztas == 3)
                    {
                        system("cls");
                        Alkalmazott::felhasznaloListaz();
                        string fnev, targy, uzenet;
                        cout << "\nKerem, szokoz helyett alsovonast (_) hasznaljon!\n" << endl;
                        cout << "\nHa nem szeretne senkinek ertesitest kuldeni, irjon be egy nullat (0)!" << endl;
                        cout << "Kerem valasszon a megadott felhasznalok kozul, es irja be a nevet: ";
                        cin >> fnev;
                        if (fnev == "0")
                        {
                            cout << "Ertesites megszakitva!" << endl;
                        }
                        else
                        {
                            cout << "Kerem adja meg az ertesites targyat: ";
                            cin >> targy;
                            cout << "Kerem irja be az ertesites uzenetet: ";
                            cin >> uzenet;

                            Ertesitesek::ertesites(fnev, targy, uzenet + "_Kuldo:_" + felhasznalonev + "_nevu_alkalmazott.", " "+felhasznalonev);
                        }
                        _getch();
                    }

                    if (valasztas == 4)
                    {
                        system("cls");
                        Alkalmazott::addFelhasznaloFigyelmeztetes(felhasznalonev);
                        _getch();

                    }

                    if (valasztas == 5)
                    {
                        system("cls");
                        Alkalmazott::keszletFeltoltesiIgeny(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == 6)
                    {
                        system("cls");
                        Alkalmazott::addRangSzamlalo(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == 7)
                    {
                        system("cls");
                        cout << "\nA on szamara beerkezett ertesitesek listaja: " << endl;
                        Ertesitesek::ertesitesLekeres(felhasznalonev);
                        _getch();                    
                    }

                    if (valasztas == 8)
                    {
                        vege = true;
                        AllatMenhely::kijelentkezes();
                    }

                    else
                    {
                        Hiba();
                    }
                    } while (!vege);

            } 
            break;
            /*case default: ??? exception
            {

            }*/
            }
            }
        }
        }

            if (valasztas == 2)
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
                if (!(AllatMenhely::ellenorizFoglaltFelhasznalonev(felhasznalonev)))
                {
                    AllatMenhely::regisztracio(felhasznalonev, jelszo);
                }
                
                _getch();
            }

            if (valasztas == 3)
            {
                kilep = true;
            }

            else
            {    
               //cout << "Hibas megadott opcio! A rendszer visszalep a menube." << endl; // nemjo??
               AllatMenhely::kijelentkezes();
            }

        }while (!kilep);

        return  0;
}


