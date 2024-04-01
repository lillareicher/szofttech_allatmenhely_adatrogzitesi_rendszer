#include "adminisztrator.h"


Adminisztrator::Adminisztrator()
{
}

void Adminisztrator::felhasznaloTorles(const string &felhasznalonev) 
{
    cout << "Felhasznalok listaja: \n" << endl;
    felhasznaloListaz();

    string fnev;
    bool sikeres = false;
    cout << "\nHa megsem szeretne torolni felhasznalot, irjon be egy nullat (0)!" << endl;
    cout << "Kerem adja meg a torolni kivant felhasznalo nevet: ";
    cin >> fnev;
    if (fnev != "0" && fnev!=felhasznalonev) {

        ifstream inputFile("felhasznalok.txt");
        ofstream outPutFile("temp.txt", ios::app);
        if (outPutFile.is_open() && inputFile.is_open())
        {
            while (!inputFile.eof())
            {
                string nev, jelszo;
                int szerep, rang, egyenleg, menhelye, rangSzamlalo;
                bool figyelmeztetes;
                inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
                if (fnev != nev && fnev != "" && nev!= "")
                {
                    outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
                if (fnev == nev) {
                    sikeres = true;
                }
            }

            inputFile.close();
            remove("felhasznalok.txt");
            outPutFile.close();
            rename("temp.txt", "felhasznalok.txt");
        }

        if (sikeres)
        {
            cout << "Sikeres torles." << endl;
        }
        else
        {
            cout << "Sikertelen torles!" << endl;
        }
    }
    else cout << "\nFelhasznalo torles megszakitva!" << endl;
}

void Adminisztrator::rangAdas(const string &felhasznalonev, int ertek)
{
    ifstream inputFile("felhasznalok.txt");
    ofstream outPutFile("temp.txt", ios::app);
    bool sikerult = false;

    if(outPutFile.is_open() && inputFile.is_open())
    { 
        while (!inputFile.eof())
        {
            string nev = "";
            string jelszo;
            int szerep, rang, egyenleg, menhelye, rangSzamlalo;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;

            if (nev == felhasznalonev && ertek!= rang && ertek>=0 && ertek <3)
            {
                outPutFile << nev << " " << jelszo << " " << szerep << " " << ertek << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                sikerult = true;
            }
            else
            {
                outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
            }
            
        }
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }

    if (sikerult)
    {
        cout << "Sikeres rangadas." << endl;
    }
    else
    {
        cout << "Sikertelen rangadas." << endl;
    }
}

void Adminisztrator::szerepkorAdas(const string& felhasznalonev, int ertek)
{
    ifstream inputFile("felhasznalok.txt");
    ofstream outPutFile("temp.txt", ios::app);
    bool sikerult = false;


    if (outPutFile.is_open() && inputFile.is_open())
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
                if (nev == felhasznalonev && ertek != szerep && ertek >= 1 && ertek <4)
                {
                    outPutFile << nev << " " << jelszo << " " << ertek << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    sikerult = true;
                }
                else
                {
                    outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
            }
        }
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }

    if (sikerult)
    {
        cout << "\nSikeres szerepkoradas!" << endl;
    }
    else
    {
        cout << "\nSikertelen szerepkoradas, helytelen erteket adott meg, vagy az adott felhasznalo mar a megadott szerepkorben van." << endl;
    }
}

void Adminisztrator::kervenyFelulvizsgalat(int testid)
{
    bool talalt = false;
    bool helyes = false;
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string ktargy, kerveny;
            string nev;
            int statusz, id;
            inputFile >> ktargy >> kerveny >> nev >> statusz >> id;
            if (id == testid) talalt = true;
            if (nev != "" && ktargy != "" && kerveny != "")
            {
                helyes = true;
            }            
        }
        if(helyes) cout << "A kerveny formatuma helyes." << endl;
        else cout << "A kerveny hibas." << endl;
        if (!talalt)
        {
            cout << "A keresett kerveny nem talalhato." << endl;
        }
        inputFile.close();
    }
}

bool Adminisztrator::letezoFelhasznalo(const string& felhasznalonev)
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

            if (nev == felhasznalonev)
            {
                return true;
            }
        }
        return false;
        inputFile.close();
    }
}

void Adminisztrator::felhasznaloListaz()
{
    cout << "A felhasznalok listazasa: \n" << endl;

    ifstream inputFile("felhasznalok.txt");


    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string nev = "";
            string jelszo = "";
            int szerep, rang, egyenleg, menhelye, rangSzamlalo;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;
            if(nev!="")
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
                    cout << ", Figyelmeztetes: van " << endl;
                }
                else
                {
                    cout << ", Figyelmeztetes: nincs " << endl;
                }
            }

        }
        inputFile.close();
        
    }

}
