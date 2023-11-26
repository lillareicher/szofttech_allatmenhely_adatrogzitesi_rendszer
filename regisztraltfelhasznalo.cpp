#include "regisztraltfelhasznalo.h"
#include <iostream>

Egyenleg RegisztraltFelhasznalo::getFelhasznaloEgyenleg() const
{
    return felhasznaloEgyenleg;
}

RegisztraltFelhasznalo::RegisztraltFelhasznalo(Rang _rang, Egyenleg _felhasznaloEgyenleg, const string& _nev, const string& _jelszo)
    : Felhasznalo(_nev, _jelszo), rang(_rang), felhasznaloEgyenleg(_felhasznaloEgyenleg) {
}

Egyenleg& Egyenleg::operator+=(const Egyenleg& other) {

    this->egyenleg += other.egyenleg;
    return *this;
}


void RegisztraltFelhasznalo::addFelhasznaloEgyenleg(const Egyenleg& feltoltottEgyenleg) {
    felhasznaloEgyenleg += feltoltottEgyenleg;
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

void RegisztraltFelhasznalo::onkentesIdopontFoglalas(string felhasznalonev)
{
    cout << "Melyik idopontot szeretned lefoglalni? Ird be a datumot szokozokkel elvalasztva! ";
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
            int eletkor, allatrang;
            inputFile >> nev >> eletkor >> nem >> allatrang >> allapot;
            cout << "Nev: " << nev << ", Eletkor: " << eletkor << ", nem: " << nem << ", Kezelhetoseg: " << allatrang << ", Egeszsegugyi allapot: " << allapot << endl;
        }
    }

    inputFile.close();

}

void RegisztraltFelhasznalo::allatSzabadKilistaz()
{
    string searchName = "";
    cout << "Melyik allathoz szeretnel idopontot foglalni?";
    cin >> searchName;
    ifstream inputFile("AllatFoglalt.txt");

    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string name;
            int year, month, day, hour;
            bool foglalt;
            vector<int> numbers;

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
    string nev;
    int ev, honap, nap, ora;

    cout << "Ird be az allat nevet, evet, honapot es napot szokozokkel elvalasztva: ";
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
    cout << "Idopont lefoglalva." << endl;
}
