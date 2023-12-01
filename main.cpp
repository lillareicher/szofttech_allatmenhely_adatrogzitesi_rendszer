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
#include "ugyintezo.h"
#include "alkalmazott.h"

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
        cout << endl;
        cin >> valasztas;

        if (valasztas == '1')
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
                cout << "\nBejelentkezes sikertelen. Hibas felhasznalonev vagy jelszo.\n" << endl;
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
                char valasztas;
                cout << "Valasszon az elerheto funckiok kozul: \n";
                cout << "1. Rangadas\n";
                cout << "2. Felhasznalok listazasa\n";
                cout << "3. Felhasznalo torlese\n";
                cout << "4. Kerveny felulvizsgalata\n";
                cout << "5. Kijelentkezes\n";

                cin >> valasztas;
                cout << endl;

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
                    AllatMenhely::kijelentkezes();
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
                    cout << "3. Virtualis orokbefogadas\n";
                    cout << "4. Idopontfoglalas\n";
                    cout << "5. Orokbefogadasi kerveny leadasa\n";
                    cout << "6. Uzenetek megtekintese\n";
                    cout << "7. Ertesitesek megtekintese\n";
                    cout << "8. Kijelentkezes\n";

                    cin >> valasztas;
                    cout << endl;

                    if (valasztas == '1')
                    {
                        system("cls");
                        RegisztraltFelhasznalo::addFelhasznaloEgyenleg(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == '2')
                    {
                        system("cls");
                        RegisztraltFelhasznalo::adomanyozasMenhelynek(felhasznalonev);
                        _getch();

                    }

                    if (valasztas == '3')
                    {
                        system("cls");
                        RegisztraltFelhasznalo::virtualisOrokbefogas(felhasznalonev);
                        _getch();

                    }

                    if (valasztas == '4')
                    {
                        bool segitovege = false;
                        do{
                            
                            system("cls");
                            char segitovalaszt;
                            cout << "Valasszon az alabbi opciok kozul: \n";
                            cout << "1. Kutyasetaltatas\n";
                            cout << "2. Onkenteskedes\n";
                            cout << "3. Visszalepes\n";
                            cin >> segitovalaszt;

                            if (segitovalaszt == '1')
                            {
                                system("cls");
                                RegisztraltFelhasznalo::allatIdoPontFoglalas(felhasznalonev);
                                _getch();
                            }
                            if (segitovalaszt == '2')
                            {
                                system("cls");
                                RegisztraltFelhasznalo::onkentesIdopontFoglalas(felhasznalonev);
                                _getch();
                            
                            }
                            if (segitovalaszt == '3')
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

                    if (valasztas == '5')
                    {
                        system("cls");
                        RegisztraltFelhasznalo::kervenyLeadas(felhasznalonev);
                    }

                    if (valasztas == '6')
                    {
                        system("cls");
                        cout << "A on szamara beerkezett uzenetek listaja: " << endl;
                        Ertesites::uzenetLekeres(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == '7')
                    {
                        system("cls");
                        cout << "A on szamara beerkezett ertesitesek listaja: " << endl;
                        Ertesites::ertesitesLekeres(felhasznalonev);
                        _getch();
                    }

                    if (valasztas == '8')
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
                char valasztas;
                system("cls");
                cout << "Valasszon az elerheto funckiok kozul: \n";
                cout << "1. Idopontok letrehozasa\n";
                cout << "2. Felhasznalo ertesitese\n";               
                cout << "3. Menhely egyenlegenek feltoltese\n";
                cout << "4. Keszletfeltoltes kezdemenyezese\n";
                cout << "5. Uzenetek megtekintese\n";
                cout << "6. Ertesitesek megtekintese\n";
                cout << "7. Kerveny elfogadasa\n";
                cout << "8. Kerveny elutasitasa\n";
                cout << "9. Kijelentkezes\n";
                cin >> valasztas;
                cout << endl;

                if (valasztas == '1')
                {
                    system("cls");
                    bool segitovege = false;
                    do {

                        system("cls");
                        char segitovalaszt;
                        cout << "Valasszon az alabbi opciok kozul: \n";
                        cout << "\n1. Kutyasetaltatas tipusu idopont letrehozasa\n";
                        cout << "2. Onkenteskedes tipusu idopont letrehozasa\n";
                        cout << "3. Visszalepes\n";
                        cin >> segitovalaszt;


                        
                        if (segitovalaszt == '1')
                        {
                            system("cls");
                            Ugyintezo::addSetaltatasIdopont();
                            _getch();   
                        }

                        if (segitovalaszt == '2')
                        {
                            system("cls");
                            Ugyintezo::addOnkentesIdopont();
                            _getch();
                        }
                        if (segitovalaszt == '3')
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

                if (valasztas == '2')
                {
                    system("cls");
                    Ertesites::uzenet();
                    _getch();
                }

                if (valasztas == '3')
                {
                    system("cls");
                    Ugyintezo::setMenhelyEgyenleg();
                    _getch();
                }

                if (valasztas == '4')
                {
                    system("cls");
                    Ugyintezo::keszletFeltoltes();
                    _getch();
                }

                if (valasztas == '5')
                {
                    system("cls");
                    cout << "A on szamara beerkezett uzenetek listaja: " << endl;
                    Ertesites::uzenetLekeres(felhasznalonev);
                    _getch();
                }

                if (valasztas == '6')
                {
                    system("cls");
                    cout << "A on szamara beerkezett ertesitesek listaja: " << endl;
                    Ertesites::ertesitesLekeres(felhasznalonev);
                    _getch();
                }

                if (valasztas == '7')
                {
                    system("cls");
                    Ugyintezo::kervenyElfogadas();
                    _getch();
                }

                if (valasztas == '8')
                {
                    system("cls");
                    Ugyintezo::kervenyElutasitas();
                    _getch();
                }

                if (valasztas == '9')
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

            case 3:
            {
                do{
                char valasztas;
                system("cls");
                cout << "Valasszon az elerheto funckiok kozul: \n";
                cout << "1. Allatok adatainak feltoltese\n";
                cout << "2. Felhasznalo ertesitese\n";
                cout << "3. Panasz benyujtasa felhasznalora\n";
                cout << "4. Keszletfeltoltesi igeny benyujtasa\n";
                cout << "5. Felhasznalo rangpontjainak novelese\n";
                cout << "6. Ertesitesek megtekintese\n";
                cout << "7. Kijelentkezes\n";
                cin >> valasztas;
                cout << endl;

                if (valasztas == '1')
                {
                    system("cls");
                    Alkalmazott::allatAdatFeltoltes();
                    _getch();
                }

                if (valasztas == '2')
                {
                    system("cls");
                    Ertesites::uzenet();
                    _getch();

                }

                if (valasztas == '3')
                {
                    system("cls");
                    Alkalmazott::addFelhasznaloFigyelmeztetes();
                    _getch();

                }

                if (valasztas == '4')
                {
                    system("cls");
                    Alkalmazott::keszletFeltoltesiIgeny();
                    _getch();
                }

                if (valasztas == '5')
                {
                    system("cls");
                    Alkalmazott::addRangSzamlalo();
                    _getch();
                }

                if (valasztas == '6')
                {
                    system("cls");
                    cout << "A on szamara beerkezett uzenetek listaja: " << endl;
                    Ertesites::ertesitesLekeres(felhasznalonev);
                    _getch();                    
                }

                if (valasztas == '7')
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
                if (!(AllatMenhely::ellenorizFoglaltFelhasznalonev(felhasznalonev)))
                {
                    AllatMenhely::regisztracio(felhasznalonev, jelszo);
                }
                
                _getch();
            }

            if (valasztas == '3')
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


