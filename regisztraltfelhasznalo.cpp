#include "regisztraltfelhasznalo.h"
#include <iostream>
#include "Egyenleg.h"
#include "kervenyek.h"
#include "allatok.h"
#include "hiba.h"
#include "idopontok.h"

int RegisztraltFelhasznalo::rangSzamlalo = 0;

RegisztraltFelhasznalo::RegisztraltFelhasznalo(Rang _rang, const string& _nev, const string& _jelszo)
    : Felhasznalo(_nev, _jelszo), rang(_rang) {
}



void RegisztraltFelhasznalo::adomanyozasMenhelynek(const string& felhasznalonev)
{

    cout << "Mennyit szeretne adomanyozni a menhelynek? ";
    int osszeg = Hiba::intBekerHiba();
    if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= osszeg && Felhasznalo::egyUgyintezoVan() == true) {
        int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) - osszeg;
        Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
        Felhasznalo::addUgyintezoEgyenleg(osszeg);

        cout << "Sikeresen adomanyozott: " << osszeg << " Ft. osszeget a menhelynek!" << endl;
        cout << "Fennmarado egyenlege: " << ujegyenleg << " Ft." << endl;
    }
    else if(Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) < osszeg)
    {
        Hiba::folyositasiHiba();
        /*cout << "Hiba! Nincs eleg egyenlege, vagy jelenleg nem elerheto az adomanyozas funkcio." << endl;*/
        Hiba::folyositasiHibaleiras();
    }
    else
    {
        cout << "Rendszerhiba!" << endl;
    }
}

void RegisztraltFelhasznalo::virtualisOrokbefogas(const string& felhasznalonev)
{
    cout << "A menhelyi allatok kilistazasa: " << endl;
    RegisztraltFelhasznalo::allatokKilistaz();
    string allatnev;
    cout << "\nMelyik allat reszere szeretne adomanyozni?: ";
    cin >> allatnev;
    if(Allatok::allatVan(allatnev)){
    cout << "\nMennyit szeretne adomanyozni?: ";
    int osszeg = Hiba::intBekerHiba();
    if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= osszeg && Allatok::allatVan(allatnev)) {
        int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) - osszeg;
        Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
        Allatok::addAllatEgyenleg(allatnev, osszeg);
        cout << "\nSikeresen adomanyozott: " << osszeg << " Ft. osszeget " << allatnev << " reszere." << endl;
    }
    else if(Egyenleg::getFelhasznaloEgyenleg(felhasznalonev)<osszeg)
    {
        Hiba::folyositasiHiba();
        /*cout << "\nHiba! Nincs eleg egyenlege, vagy nincs ilyen allat a menhelyen." << endl;*/
        Hiba::folyositasiHibaleiras();
    }
    else
    {
        cout << "\nHiba! Nincs ilyen allat a menhelyen." << endl;
    }
    }
    else cout << "Nincs ilyen allat a menhelyen!" << endl;
}

void RegisztraltFelhasznalo::addFelhasznaloEgyenleg(const string& felhasznalonev)
{

    int uj;
    cout << "Mekkora osszeget szeretne feltolteni? (Ft): ";
    int feltoltes = Hiba::intBekerHiba();
    if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= 0) {
        uj = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) + feltoltes;
        Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, uj);
        cout << "\nSikeres feltoltes!" << endl;
    }
    else {
        cout << "\nSikertelen feltoltes." << endl;
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
    bool sikeresLefoglalas = false;
    cout << "Az elerheto idopontok es tevekenysegek onkenteskedesre: \n" << endl;
    onkentesSzabadKilistaz();

    cout << "\nMelyik idopontot szeretned lefoglalni? Ird be a datumot szokozokkel elvalasztva! (ev, honap, nap, ora): ";
    int ev = Hiba::intBekerHiba();
    int honap = Hiba::intBekerHiba();
    int nap = Hiba::intBekerHiba();
    int ora = Hiba::intBekerHiba();
    string felhasznalo, tevekenyseg;
    ofstream outPutFile("temp.txt", ios::app);
    ifstream inputFile("Foglalasok.txt");
    if(Idopontok::validDatum(ev, honap, nap, ora)){
        if (outPutFile.is_open() && inputFile.is_open()) {
            while (!inputFile.eof()) {
                int _ev, _honap, _nap, _ora;
                string _felhasznalo, _tevekenyseg;
                inputFile >> _tevekenyseg >> _ev >> _honap >> _nap >> _ora >> _felhasznalo;
                if (_tevekenyseg != "") {
                    if (_ev == ev && _honap == honap && nap == _nap && ora == _ora) {
                        outPutFile << _tevekenyseg << " " << _ev << " " << _honap << " " << _nap << " " << _ora << " " << felhasznalonev << endl;
                        sikeresLefoglalas = true;
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
        if(sikeresLefoglalas)
        cout << "\nIdopont sikeresen lefoglalva!" << endl;
        else {
        cout << "Sikertlen lefoglalas, nincs ilyen szabad idopont." << endl;
        }
    }
    else cout << "Sikertelen lefoglalas, nem valid datum!" << endl;
}

void RegisztraltFelhasznalo::allatokKilistaz()
{
    ifstream inputFile("allatok.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, nem, allapot;
            int eletkor, allatrang, allatEgyenleg;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot >> allatEgyenleg;
            if (nev != "") {
                cout << "Nev: " << nev << ", Eletkor: " << eletkor << ", nem: " << nem << ", Kezelhetoseg: " << allatrang << ", Egeszsegugyi allapot: " << allapot << endl;
            }
        }
    }

    inputFile.close();

}

bool RegisztraltFelhasznalo::allatSzabadKilistaz(const string& felhasznalonev)
{
    int felhRang = getRang(felhasznalonev);
    string searchName = "";
    cout << "\nMelyik allathoz szeretne idopontot foglalni?: ";
    cin >> searchName;
    bool megfelel = (Allatok::getAllatRang(searchName) <= getRang(felhasznalonev) && Allatok::allatVan(searchName));
    if (megfelel) {
        ifstream inputFile("allatFoglalt.txt");

        if (inputFile.is_open()) {
            while (!inputFile.eof()) {
                string name, felh;
                int year, month, day, hour;
                bool foglalt;
                vector<int> numbers; //?

                inputFile >> name >> year >> month >> day >> hour >> foglalt >> felh;
                if (name == searchName && !foglalt && felhRang >= Allatok::getAllatRang(name)) {
                    cout << "Szabad idopont talalva '" << searchName << "' -nak/nek: " << year << "-" << month << "-" << day << " " << hour << ":00" << endl;
                }
            }
            inputFile.close();
        }
        return megfelel;
    }
    else if(Allatok::allatVan(searchName)){
        cout << "Nem megfelelo a rangszint az allathoz. Probalja meg rangszintjet novelni onkenteskedessel!" << endl;
        return megfelel;
    }
    else if(!Allatok::allatVan(searchName)){
        cout << "Nem letezik ilyen allat a menhelyen." << endl;
    }
    return megfelel;
}

void RegisztraltFelhasznalo::allatIdoPontFoglalas(const string& felhasznalonev)
{
    cout << "A menhelyi allatok listaja: \n";
    allatokKilistaz();

    if (allatSzabadKilistaz(felhasznalonev) == true) {

        string nev;
        bool talalt = false;
        cout << "\nKerem irja be a valasztott allat nevet, evet, honapot es napot szokozokkel elvalasztva: ";
        cin >> nev;
        int ev = Hiba::intBekerHiba();
        int honap = Hiba::intBekerHiba();
        int nap = Hiba::intBekerHiba();
        int ora = Hiba::intBekerHiba();
        if (Allatok::allatVan(nev) == true) {
            if (Allatok::getAllatRang(nev) <= getRang(felhasznalonev)) {
                ifstream inputFile("AllatFoglalt.txt");
                ofstream outPutFile("temp.txt", ios::app);

                if (outPutFile.is_open() && inputFile.is_open()) {
                    while (!inputFile.eof()) {
                        string _nev = "", felh;
                        int year, month, day, hour;
                        bool foglalt;
                        inputFile >> _nev >> year >> month >> day >> hour >> foglalt >> felh;
                        if (_nev != "") {
                            if (nev == _nev && year == ev && month == honap && nap == day && ora == hour) {
                                talalt = true;
                                outPutFile << _nev << " " << year << " " << month << " " << day << " " << hour << " " << 1 << " " << felhasznalonev << endl;
                            }
                            else {
                                outPutFile << _nev << " " << year << " " << month << " " << day << " " << hour << " " << foglalt << " " << felh << endl;
                            }
                        }

                    }
                    inputFile.close();
                    remove("allatFoglalt.txt");
                    outPutFile.close();
                    rename("temp.txt", "allatFoglalt.txt");
                }
                if (talalt == true) {
                    cout << "Idopont sikeresen lefoglalva." << endl;
                }
                else {
                    cout << "Idopont hibasan lett megadva. Nem sikerult lefoglalni." << endl;
                }
            }
            else {
                cout << "Nem megfelelo a rangszint az idopont lefoglalasahoz. Probalja meg rangszintjet novelni onkenteskedessel!" << endl;
            }
        }
        else {
            cout << "Nem talalhato ilyen allat." << endl;
        }
    }
}

void RegisztraltFelhasznalo::kervenyLeadas(const string& felhasznalonev)
{
    kervenyek uj("", "");
    ofstream outPutFile("kervenyek.txt", ios::app);
    cout << "\nKerem adja meg a kerveny targyat: ";
    cin >> uj.kervenyTargy;
    cout << "\nKerem adja meg a kerveny szoveget (szokozok helyett alulvonast (_) hasznaljon): ";
    cin >> uj.kerveny;

    if (outPutFile.is_open()) {
        string targy, kerveny, nev;
        bool elfogadva = 0;
        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << felhasznalonev << " " << elfogadva << endl;
    }
    outPutFile.close();
    cout << "\nKerveny leadva." << endl;
}
