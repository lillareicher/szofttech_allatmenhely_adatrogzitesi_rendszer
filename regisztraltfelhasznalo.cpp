#include "regisztraltfelhasznalo.h"
#include <iostream>
#include "Egyenleg.h"
#include "kervenyek.h"
#include "allatok.h"

int RegisztraltFelhasznalo::rangSzamlalo = 0;

RegisztraltFelhasznalo::RegisztraltFelhasznalo(Rang _rang, const string& _nev, const string& _jelszo)
    : Felhasznalo(_nev, _jelszo), rang(_rang) {
}

int RegisztraltFelhasznalo::getRangSzamlalo(const string &felhasznalonev)
{
        ifstream inputFile("felhasznalok.txt");
        int rangsz = -1;
        if (inputFile.is_open()) {
            while (!inputFile.eof()) {
                string nev, jelszo;
                int szerep, rang, menhelye, rangSzamlalo, egy;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (felhasznalonev == nev) {
                    rangsz = rangSzamlalo;
                }
            }

        }
        inputFile.close();
        return rangsz;
}

void RegisztraltFelhasznalo::addRangSzamlalo(const string &felhasznalonev, int add)
{
//        Kezdő 0-25 Középhalado 25 - 75 Halado 75
        ofstream outPutFile("temp.txt", ios::app);
        ifstream inputFile("felhasznalok.txt");
        int ujRangSzamlalo = getRangSzamlalo(felhasznalonev) + add;
        int regiRangSzamlalo = getRangSzamlalo(felhasznalonev);
        if(getRangSzamlalo(felhasznalonev)<75 && (add !=0) && ujRangSzamlalo <76){
            if (outPutFile.is_open() && inputFile.is_open()) {
                while (!inputFile.eof()) {
                    string nev, jelszo;
                    int szerep, rang, menhelye, rangSzamlalo, egy;
                    bool figyelmeztetes;
                    inputFile >> nev >> jelszo >> szerep >> rang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
                    if (nev != "") {
                        if (nev == felhasznalonev) {
                            outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egy << " " << menhelye << " " << ujRangSzamlalo << " " << figyelmeztetes << endl;
                        }
                        else {
                            outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egy << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                        }
                    }

                }
                inputFile.close();
                remove("felhasznalok.txt");
                outPutFile.close();
                rename("temp.txt", "felhasznalok.txt");
                cout << "Sikeres a rangszamlalo novelese " << add << "-el, " << "az uj rangertek = " << ujRangSzamlalo << endl;
                if(regiRangSzamlalo < 25 && ujRangSzamlalo <75 && ujRangSzamlalo > 24){
                    Rang::setRang(felhasznalonev, 1);
                    cout << felhasznalonev << " Szintet lepett! Az uj rangja Kozephalado." << endl;
                }
                if(ujRangSzamlalo == 75 && regiRangSzamlalo < 75){
                    Rang::setRang(felhasznalonev, 2);
                    cout << felhasznalonev << " Szintet lepett! Az uj rangja Halado." << endl;
                }

            }
        }
        else {
            cout << "Sikertelen a rangszamlalo novelese" << endl;
        }
}

void RegisztraltFelhasznalo::rangSzamlaloBeallitas(const string &felhasznalonev)
{
        ifstream inputFile("felhasznalok.txt");
        int rangLeker = -1;
        int rangSzamlal = -1;
        if (inputFile.is_open()) {
            while (!inputFile.eof()) {
                string nev, jelszo;
                int szerep, jrang, menhelye, rangSzamlalo, egy;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> jrang >> egy >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (felhasznalonev == nev) {
                    rangSzamlal = rangSzamlalo;
                    rangLeker = jrang;
                }
            }

        }
        inputFile.close();
        if(rangLeker != -1 && rangSzamlal !=-1){

        }
}

void RegisztraltFelhasznalo::adomanyozasMenhelynek(const string &felhasznalonev)
{
        int osszeg;
        cout << "Mennyit szeretne adomanyozni a menhelynek? ";
        cin >> osszeg;
        if(Egyenleg::getFelhasznaloEgyenleg(felhasznalonev)>= osszeg && Felhasznalo::egyUgyintezoVan() == true){
            int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev)-osszeg;
            Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
            Felhasznalo::addUgyintezoEgyenleg(osszeg);

            cout << "Sikeresen adomanyozott: " << osszeg << " osszeget a menhelynek!" << endl;
            cout << "Fennmarado egyenlege: " << ujegyenleg << endl;
        }
        else {
            cout << "Hiba! Nincs eleg egyenlege vagy nem lehet jelenleg adomanyozni." << endl;
        }
}

void RegisztraltFelhasznalo::virtualisOrokbefogas(const string &felhasznalonev)
{
        RegisztraltFelhasznalo::allatokKilistaz();
        string allatnev;
        int osszeg;
        cout << "Kinek szeretnel adomanyozni? ";
        cin >> allatnev;
        cout << "Mennyit szeretnel adomanyozni? ";
        cin >> osszeg;
        if(Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= osszeg && Allatok::allatVan(allatnev)){
            int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev)-osszeg;
            Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
            Allatok::addAllatEgyenleg(allatnev, osszeg);
            cout << "Sikeresen adomanyozott: " << osszeg << " osszeget, " << allatnev << " - nak/nek." << endl;
        }
        else {
            cout << "Hiba! Nincs eleg egyenlege vagy nincs ilyen allat a menhelyen." << endl;
        }

}

void RegisztraltFelhasznalo::addFelhasznaloEgyenleg(const string& felhasznalonev)
{
    int feltoltes;
    int uj;
    cout << "Mennyi penzt szeretne feltolteni?";
    cin >> feltoltes;
    if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= 0) {
        uj = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) + feltoltes;
        Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, uj);
        cout << "Sikeres feltoltes";
    }
    else {
        cout << "Sikertelen feltoltes";
    }
}

void RegisztraltFelhasznalo::onkentesSzabadKilistaz()
{
    ifstream inputFile("Foglalasok.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string felhasznalo, tevekenyseg;
            int ev, honap, nap, ora;
            inputFile >> tevekenyseg >> ev >> honap >> nap >> ora >> felhasznalo;
            if (felhasznalo == "senki" && tevekenyseg != "") {
                cout << "Tevekenyseg: " << tevekenyseg << " ev: " << ev << " honap: " << honap << " nap: " << nap << " ora: " << ora << " lefoglalta eddig: " << felhasznalo << endl;

            }
        }

    }
    inputFile.close();
}

void RegisztraltFelhasznalo::onkentesIdopontFoglalas(const string& felhasznalonev)
{
    cout << "\nAz elerheto idopontok es tevekenysegek onkenteskedesre: " << endl;
    onkentesSzabadKilistaz();

    cout << "\nMelyik idopontot szeretned lefoglalni? Ird be a datumot szokozokkel elvalasztva! (ev, honap, nap, ora): ";
    int ev, honap, nap, ora;
    string felhasznalo, tevekenyseg;
    cin >> ev >> honap >> nap >> ora;
    ofstream outPutFile("temp.txt", ios::app);
    ifstream inputFile("Foglalasok.txt");

    if (outPutFile.is_open() && inputFile.is_open()) {
        while (!inputFile.eof()) {
            int _ev, _honap, _nap, _ora;
            string _felhasznalo, _tevekenyseg;
            inputFile >> _tevekenyseg >> _ev >> _honap >> _nap >> _ora >> _felhasznalo;
            if (_tevekenyseg != "") {
                if (_ev == ev && _honap == honap && nap == _nap && ora == _ora) {
                    outPutFile << _tevekenyseg << " " << _ev << " " << _honap << " " << _nap << " " << _ora << " " << felhasznalonev << endl;
                }
                else {
                    outPutFile << _tevekenyseg << " " << ev << " " << _honap << " " << _nap << " " << _ora << " " << _felhasznalo << endl;
                }
            }

        }
        inputFile.close();
        remove("Foglalasok.txt");
        outPutFile.close();
        rename("temp.txt", "Foglalasok.txt");
    }
    cout << "Idopont lefoglalva." << endl;
}

void RegisztraltFelhasznalo::allatokKilistaz()
{
    ifstream inputFile("Allatok.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if (nev != ""){
            cout << "Nev: " << nev << ", Eletkor: " << eletkor << ", nem: " << nem << ", Kezelhetoseg: " << allatrang << ", Egeszsegugyi allapot: " << allapot << endl;
            }
        }
    }

    inputFile.close();

}

void RegisztraltFelhasznalo::allatSzabadKilistaz()
{
    string searchName = "";
    cout << "\nMelyik allathoz szeretne idopontot foglalni?: ";
    cin >> searchName;
    ifstream inputFile("AllatFoglalt.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string name;
            int year, month, day, hour;
            bool foglalt;
            vector<int> numbers; //?

            inputFile >> name >> year >> month >> day >> hour >> foglalt;
            if (name == searchName && !foglalt) {
                cout << "Szabad idopont talalva '" << searchName << "' -nak/nek: " << year << "-" << month << "-" << day << " " << hour << ":00" << endl;
            }
        }
        inputFile.close();
    }
}

void RegisztraltFelhasznalo::allatIdoPontFoglalas()
{
    cout << "\nA menhelyi allatok listaja: \n";
    allatokKilistaz();

    allatSzabadKilistaz();

    string nev;
    int ev, honap, nap, ora;

    cout << "\nKerem irja be a valasztott allat nevet, evet, honapot es napot szokozokkel elvalasztva: ";
    cin >> nev >> ev >> honap >> nap >> ora;
    ifstream inputFile("AllatFoglalt.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (outPutFile.is_open() && inputFile.is_open()) {
        while (!inputFile.eof()) {
            string _nev = "";
            int year, month, day, hour;
            bool foglalt;
            inputFile >> _nev >> year >> month >> day >> hour >> foglalt;
            if (_nev != "") {
                if (nev == _nev && year == ev && month == honap && nap == day && ora == hour) {
                    outPutFile << _nev << " " << year << " " << month << " " << day << " " << hour << " " << 1 << endl;
                }
                else {
                    outPutFile << _nev << " " << year << " " << month << " " << day << " " << hour << " " << foglalt << endl;
                }
            }

        }
        inputFile.close();
        remove("AllatFoglalt.txt");
        outPutFile.close();
        rename("temp.txt", "AllatFoglalt.txt");
    }
    cout << "Idopont sikeresen lefoglalva." << endl;
}

void RegisztraltFelhasznalo::kervenyLeadas(const string& felhasznalonev)
{
    kervenyek uj("", "");
    ofstream outPutFile("kervenyek.txt", ios::app);
    cout << "Mi a kerveny targya?: ";
    cin >> uj.kervenyTargy;
    cout << "Mi a kerveny szovege? A szokozok helyett alulvonast hasznaljon (_) :";
    cin >> uj.kerveny;

    if (outPutFile.is_open()) {
        string targy, kerveny, nev;
        bool elfogadva = 0;
        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << felhasznalonev << " " << elfogadva << endl;
    }
    outPutFile.close();
    cout << "Kerveny leadva." << endl;
}
