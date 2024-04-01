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
    cout << "Jelenlegi egyenlege : " << Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) << " Ft." << endl;
    cout << "\nHa megsem szeretne adomanyozni, irjon be egy nullat (0)!" << endl;
    cout << "Adomanyozasra szant osszeg: ";
    int osszeg = Hiba::intBekerHiba();
    if (osszeg != 0) {
        if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= osszeg && Felhasznalo::egyUgyintezoVan() == true) {
            int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) - osszeg;
            Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
            Felhasznalo::addMenhelyEgyenleg(osszeg);

            cout << "\nSikeresen adomanyozott: " << osszeg << " Ft. osszeget a menhelynek!" << endl;
            cout << "Fennmarado egyenlege: " << ujegyenleg << " Ft." << endl;
        }
        else if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) < osszeg)
        {
            Hiba::folyositasiHiba();
            Hiba::folyositasiHibaleiras();
        }
        else
        {
            cout << "\nRendszerhiba! Az ugyintezok szama meghaladja a korlatot." << endl;
        }
    }
    else cout << "\nAdomanyozasi folyamat megszakitva!" << endl;
}

void RegisztraltFelhasznalo::virtualisOrokbefogas(const string& felhasznalonev)
{
    cout << "A menhelyi allatok kilistazasa: " << endl;
    RegisztraltFelhasznalo::allatokKilistaz();
    cout << "\nMelyik allat reszere szeretne adomanyozni?: ";
    string allatnev = Hiba::allatVanHiba();
    if (Allatok::allatVan(allatnev)) {
        cout << "\nAktualis egyenlege : " << Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) << " Ft." << endl;
        cout << "Ha megsem szeretne adomanyozni, irjon be egy nullat (0)!\n" << endl;
        cout << "Adomanyozasra szant osszeg: ";
        int osszeg = Hiba::intBekerHiba();
        if (osszeg != 0) {
            if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= osszeg && Allatok::allatVan(allatnev)) {
                int ujegyenleg = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) - osszeg;
                Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, ujegyenleg);
                Allatok::addAllatEgyenleg(allatnev, osszeg);
                cout << "\nSikeresen adomanyozott: " << osszeg << " Ft. osszeget " << allatnev << " reszere." << endl;
                cout << "\nFennmarado egyenlege: " << ujegyenleg << " Ft." << endl;
            }
            else if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) < osszeg)
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
        else cout << "\nAdomanyozasi folyamat megszakitva!" << endl;
    }
    else cout << "\nNincs ilyen allat a menhelyen!" << endl;
}

void RegisztraltFelhasznalo::addFelhasznaloEgyenleg(const string& felhasznalonev)
{

    int uj;
    cout << "Jelenlegi egyenlege : " << Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) << " Ft." << endl;
    cout << "Kerem adja meg a feltoltetni kivant osszeget (Ft): ";
    int feltoltes = Hiba::intBekerHiba();
    if (Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) >= 0) {
        uj = Egyenleg::getFelhasznaloEgyenleg(felhasznalonev) + feltoltes;
        Egyenleg::setFelhasznaloEgyenleg(felhasznalonev, uj);
        cout << "\nSikeresen feltoltott: " << feltoltes << " Ft-ot.\nUj egyenlege: " << uj << " Ft." << endl;
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
    if (Idopontok::validDatum(ev, honap, nap, ora)) {
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
        if (sikeresLefoglalas)
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

bool RegisztraltFelhasznalo::allatSzabadKilistaz(const string& felhasznalonev, const string& searchName)
{
    int felhRang = getRang(felhasznalonev);
    bool megfelel = (Allatok::getAllatRang(searchName) <= getRang(felhasznalonev));
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
    else if (Allatok::allatVan(searchName)) {
        cout << "Nem megfelelo a rangszint az allathoz. Probalja meg rangszintjet novelni onkenteskedessel!" << endl;
        return megfelel;
    }
    else if (!Allatok::allatVan(searchName)) {
        cout << "Nem letezik ilyen allat a menhelyen." << endl;
    }
    return megfelel;
}

void RegisztraltFelhasznalo::allatIdoPontFoglalas(const string& felhasznalonev)
{
    cout << "A menhelyi allatok listaja: \n";
    allatokKilistaz();
    cout << "\nMelyik allathoz szeretne idopontot foglalni?: ";
    string allatnev = Hiba::allatVanHiba();
    if (allatSzabadKilistaz(felhasznalonev, allatnev) == true) {

        bool talalt = false;
        cout << "\nKerem irja be az evet, honapot es napot szokozokkel elvalasztva: ";
        int ev = Hiba::intBekerHiba();
        int honap = Hiba::intBekerHiba();
        int nap = Hiba::intBekerHiba();
        int ora = Hiba::intBekerHiba();
        if (Allatok::allatVan(allatnev) == true) {
            if (Allatok::getAllatRang(allatnev) <= getRang(felhasznalonev)) {
                ifstream inputFile("AllatFoglalt.txt");
                ofstream outPutFile("temp.txt", ios::app);

                if (outPutFile.is_open() && inputFile.is_open()) {
                    while (!inputFile.eof()) {
                        string _nev = "", felh;
                        int year, month, day, hour;
                        bool foglalt;
                        inputFile >> _nev >> year >> month >> day >> hour >> foglalt >> felh;
                        if (_nev != "") {
                            if (allatnev == _nev && year == ev && month == honap && nap == day && ora == hour) {
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

void RegisztraltFelhasznalo::kervenyLeadas(const string& felhasznalonev) // 2023.12.01. modositva
{
    Kervenyek uj("", "");
    ofstream outPutFile("kervenyek.txt", ios::app);
    cout << "Ha megsem szeretne kervenyt leadni, irjon be egy nullat (0)!" << endl;
    cout << "Kerem adja meg a kerveny targyat: ";
    cin >> uj.kervenyTargy;
    if (uj.kervenyTargy != "0") {
        cout << "\nKerem adja meg a kerveny szoveget (szokozok helyett alulvonast (_) hasznaljon): ";
        cin >> uj.kerveny;
        if (outPutFile.is_open())
        {
            int id = Kervenyek::getUtolsoID() + 1;
            outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << felhasznalonev << " " << 0 << " " << id << endl;
        }
        outPutFile.close();
        cout << "\nKerveny leadva." << endl;
    }
    else cout << "\nSikertelen kervenyleadas." << endl;
}