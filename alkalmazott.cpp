#include "alkalmazott.h"

void Alkalmazott::addFelhasznaloFigyelmeztetes(const string &felhasznalonev)
{
    felhasznaloListaz();

    bool figyelm = false;
    string fnev;
    cout << "\nHa megsem szeretne figyelmeztetest adni, irjon be egy nullat (0)!\n" << endl;
    cout << "Kerem adja meg a valasztott felhasznalo nevet: ";
    cin >> fnev;
    if (fnev != "0") {
        ifstream inputFile("felhasznalok.txt");
        ofstream outputFile("tmp.txt", ios::app);

        if (inputFile.is_open() && outputFile.is_open())
        {
            while (!inputFile.eof())
            {
                string nev = "";
                string jelszo;
                int szerep, rang, egyenleg, menhelye, rangSzamlalo;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (nev != "")
                {
                    if (figyelmeztetes != 1 && nev == fnev)
                    {
                        figyelm = true;
                        outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << 1 << endl;
                        Ertesitesek::ertesites(fnev, "Figyelmeztetes", "On_figyelmeztetesben_reszesult!_"+felhasznalonev + "_nevu_alkalmazott_altal.", felhasznalonev);
                    }
                    else
                    {
                        outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }
                }
            }
            if (figyelm == true) cout << "\nA figyelmeztetes kiadasa sikeres volt." << endl;
            else cout << "\nA figyelmeztetes kiadasa sikertelen volt." << endl;

            inputFile.close();
            remove("felhasznalok.txt");
            outputFile.close();
            rename("tmp.txt", "felhasznalok.txt");
        }
    }
    else cout << "Folyamat megszakitva." << endl;
}

void Alkalmazott::keszletFeltoltesiIgeny(const string &felhasznalonev)
{
    ifstream inputFile("felhasznalok.txt");

    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string nev, jelszo;
            int szerep, rang, egyenleg, menhelye, rangSzamlalo;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (szerep == 2)
            {
                cout << "Sikeres keszletfeltoltesi igeny benyujtasa." << endl;
                Ertesitesek::ertesites(nev, "Keszletfeltoltesi_Igeny", "Szukseges_a_keszletfeltoltes_Ertesito:_"+felhasznalonev+"_nevu_alkalmazott.", " "+felhasznalonev);
            }
        }
        inputFile.close();
    }

}



void Alkalmazott::addRangSzamlalo(const string& fnev)
{
    //Kezdo 0-25, Kozephalado 25 - 75, Halado 75

    cout << "Felhasznalok listazasa: \n" << endl;
    felhasznaloListaz();

    string felhasznalonev;
    cout << "\nHa nem szeretne senkinek ertesitest kuldeni, irjon be egy nullat." << endl;
    cout << "Kerem adja meg a felhasznalo nevet: ";
    cin >> felhasznalonev;
    if (felhasznalonev != "0") {

        cout << "\nTovabba a rang novelesenek mennyiseget (0 - 25: kezdo, 25 - 75: kozephalado, 75 - : halado): ";
        int add = Hiba::intBekerHiba();

        cout << "\n";

        ofstream outPutFile("temp.txt", ios::app);
        ifstream inputFile("felhasznalok.txt");
        int ujRangSzamlalo = getRangSzamlalo(felhasznalonev) + add;
        int regiRangSzamlalo = getRangSzamlalo(felhasznalonev);
        if (getRangSzamlalo(felhasznalonev) < 75 && (add != 0) && ujRangSzamlalo < 76) {
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
                if (regiRangSzamlalo < 25 && ujRangSzamlalo < 75 && ujRangSzamlalo > 24) {
                    Rang::setRang(felhasznalonev, 1);
                    cout << felhasznalonev << " Szintet lepett! Az uj rangja Kozephalado." << endl;
                    Ertesitesek::ertesites(felhasznalonev, "Rang_modositas", "Sikeres_szintlepes_az_uj_rangja:_kozephalado!_Ertesito:_" +fnev+ "_nevu_alkalmazott.", " "+fnev);
                }
                if (ujRangSzamlalo == 75 && regiRangSzamlalo < 75) {
                    Rang::setRang(felhasznalonev, 2);
                    cout << felhasznalonev << " Szintet lepett! Az uj rangja Halado." << endl;
                    Ertesitesek::ertesites(felhasznalonev, "Rang_modositas", "Sikeres_szintlepes_az_uj_rangja:_halado!_Ertesito:_" +fnev+ "_nevu_alkalmazott.", " "+fnev);
                }
            }
        }
        else {
            cout << "Sikertelen a rangszamlalo novelese" << endl;
        }
    }
    else cout << "Rangszamlalo novelesi folyamat megszakitva. " << endl;
}

void Alkalmazott::rangSzamlaloBeallitas(const string& felhasznalonev)
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
    if (rangLeker != -1 && rangSzamlal != -1) {

    }
}


void Alkalmazott::felhasznaloListaz()
{
    cout << "A felhasznalok listaja: \n" << endl;

    ifstream inputFile("felhasznalok.txt");


    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string nev = "";
            string jelszo;
            int szerep, rang, egyenleg, menhelye, rangSzamlalo;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if (nev != "")
            {
                cout << "Felhasznalonev: " << nev << ", Szerep: ";
                switch (szerep)
                {
                case 0:
                {
                    cout << "Admin, ";
                    break;
                }
                case 1:
                {
                    cout << "Regisztralt felhasznalo, ";
                    break;
                }
                case 2:
                {
                    cout << "Ugyintezo, ";
                    break;
                }
                case 3:
                {
                    cout << "Alkalmazott, ";
                    break;
                }
                }
                cout << "Rang: ";
                switch (rang)
                {
                case 0:
                {
                    cout << "Kezdo, ";
                    break;
                }
                case 1:
                {
                    cout << "Kozephalado, ";
                    break;
                }
                case 2:
                {
                    cout << "Halado, ";
                    break;
                }
                }
                cout << "Egyenleg: " << egyenleg << " Ft., " << "Rang szamlalo: " << rangSzamlalo;
                if (figyelmeztetes)
                {
                    cout << " , Figyelmeztetes: van " << endl;
                }
                else
                {
                    cout << " , Figyelmeztetes: nincs " << endl;
                }
            }

        }
        inputFile.close();

    }

}

void Alkalmazott::allatAdatFeltoltes()
{
    string nev, nem, allapot;
    cout << "Ha megsem szeretne allatot feltolteni, irjon be egy nullat." << endl;
    cout << "Kerem adja meg a kovetkezo adatokat: " << endl;
    cout << "\nNev: ";
    cin >> nev;
    if (nev != "0") {
        cout << "Kor: ";
        int eletkor = Hiba::intBekerHiba();
        cout << "Nem: ";
        cin >> nem;
        cout << "Rang: ";
        int allatrang = Hiba::intBekerHiba();
        cout << "Egeszsegugyi allapot (szokoz helyett hasznaljon (_) karakter): ";
        cin >> allapot;
        cout << "Allat egyenlege: ";
        int allatEgyenleg = Hiba::intBekerHiba();

        cout << endl;

        ofstream outputFile("allatok.txt", ios::app);

        if (outputFile.is_open())
        {
            outputFile << nev << " " << eletkor << " " << nem << " " << allatrang << " " << allapot << " " << allatEgyenleg << endl;
        }
        outputFile.close();
        cout << "Sikeres adatfeltoltes." << endl;
    }
    else cout << "Adatfeltoltesi folyamat megszakitva." << endl;
}


