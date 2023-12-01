#include "alkalmazott.h"

void Alkalmazott::addFelhasznaloFigyelmeztetes()
{
    felhasznaloListaz();

    bool figyelm = false;
    string fnev;
    cout << "\nKerem adja meg a felhasznalo nevet: ";
    cin >> fnev;

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
            if(nev!="")
            { 
                if (figyelmeztetes != 1  && nev==fnev)
                {
                    figyelm = true;
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << 1 << endl;       
                }
                else
                {
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                } 
            }
        }
        if(figyelm==true) cout << "A figyelmeztetes kiadasa sikeres volt." << endl;
        else cout << "A figyelmeztetes kiadasa sikertelen volt." << endl;

        inputFile.close();
        remove("felhasznalok.txt");
        outputFile.close();
        rename("tmp.txt", "felhasznalok.txt");
    }
}

void Alkalmazott::keszletFeltoltesiIgeny()
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
                Ertesites::ertesites(nev, "Keszletfeltoltesi_Igeny", "Szukseges_a_keszletfeltoltes!");
                cout << "Sikeres keszletfeltoltesi igeny benyujtasa." << endl;
            }
        }
        inputFile.close();
    }

}



void Alkalmazott::addRangSzamlalo()
{
    //Kezdo 0-25, Kozephalado 25 - 75, Halado 75

    cout << "Felhasznalok listazasa: \n" << endl;
    felhasznaloListaz();

    string felhasznalonev;
    int add;
    cout << "\nKerem adja meg a felhasznalo nevet: ";
    cin >> felhasznalonev;

    cout << "\nTovabba a rang novelesenek mennyiseget: ";
    cin >> add;

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
            }
            if (ujRangSzamlalo == 75 && regiRangSzamlalo < 75) {
                Rang::setRang(felhasznalonev, 2);
                cout << felhasznalonev << " Szintet lepett! Az uj rangja Halado." << endl;
            }

        }
    }
    else {
        cout << "Sikertelen a rangszamlalo novelese" << endl;
    }
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
                case 0: szerep == 0;
                {
                    cout << "Admin, ";
                    break;
                }
                case 1: szerep == 1;
                {
                    cout << "Regisztralt felhasznalo, ";
                    break;
                }
                case 2: szerep == 2;
                {
                    cout << "Ugyintezo, ";
                    break;
                }
                case 3: szerep == 2;
                {
                    cout << "Alkalmazott, ";
                    break;
                }
                }
                cout << "Rang: ";
                switch (rang)
                {
                case 0: rang == 0;
                {
                    cout << "Kezdo, ";
                    break;
                }
                case 1: rang == 1;
                {
                    cout << "Kozephalado, ";
                    break;
                }
                case 2: rang == 2;
                {
                    cout << "Halado, ";
                    break;
                }
                }
                cout << "Egyenleg: " << egyenleg << " Ft., " << "Rang szamlalo: " << rangSzamlalo;
                if (figyelmeztetes)
                {
                    cout << " , Figyelmeztetes: van" << endl;
                }
                else
                {
                    cout << " , Figyelmeztetes: nincs" << endl;
                }
            }

        }
        inputFile.close();

    }

}

void Alkalmazott::allatAdatFeltoltes()
{
    string nev, nem, allapot;
    int eletkor, allatrang, allatEgyenleg;
    cout << "Kerem adja meg a kovetkezo adatokat: " << endl;
    cout << "\nNev: ";
    cin >> nev;
    cout << "Kor: ";
    cin >> eletkor;
    cout << "Nem: ";
    cin >> nem;
    cout << "Rang: ";
    cin >> allatrang;
    cout << "Egeszsegugyi allapot (szokoz helyett hasznaljon (_) karakter): ";
    cin >> allapot;
    cout << "Allat egyenlege: ";
    cin >> allatEgyenleg;

    cout << endl;

    ofstream outputFile("allatok.txt", ios::app);

    if (outputFile.is_open())
    {
        outputFile << nev << " " << eletkor << " " << nem << " " << allatrang << " " << allapot << " " << allatEgyenleg << endl;
    }
    outputFile.close();
    cout << "Sikeres adatfeltoltes." << endl;
   
}


