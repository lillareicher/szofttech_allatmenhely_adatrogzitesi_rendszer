#include "adminisztrator.h"


Adminisztrator::Adminisztrator(const string& _nev, int _szerepkorID, const string& _jelszo): nev(_nev), jelszo(_jelszo)
{
}

void Adminisztrator::felhasznaloTorles() 
{
    cout << "\nFelhasznalok listaja: " << endl;
    felhasznaloListaz();

    string fnev;
    cout << "\nKerem adja meg a torolni kivant felhasznalo nevet: ";
    cin >> fnev;

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
            if (fnev != nev && nev!="" && szerep!=0)
            {
                outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
            } 
        }
        
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }

    if (letezoFelhasznalo(fnev))
    {
        cout << "Sikeres torles." << endl;
    }
    else
    {
        cout << "Sikertelen torles." << endl;
    }
    
}

void Adminisztrator::rangAdas(const string &felhasznalonev, int ertek)
{
    ifstream inputFile("felhasznalok.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if(outPutFile.is_open() && inputFile.is_open())
    { 
        while (!inputFile.eof())
        {
            string nev = "";
            string jelszo;
            int szerep, rang, egyenleg, menhelye, rangSzamlalo;
            bool figyelmeztetes;
            inputFile >> nev >> jelszo >> szerep >> rang >> egyenleg >> menhelye >> rangSzamlalo >> figyelmeztetes;

            if (nev == felhasznalonev && ertek!= rang && ertek>=0)
            {
                outPutFile << nev << " " << jelszo << " " << szerep << " " << ertek << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
            }
            else if(nev!="")
            {
                outPutFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
            }
            
        }
        inputFile.close();
        remove("felhasznalok.txt");
        outPutFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }

    if (letezoFelhasznalo(felhasznalonev))
    {
        cout << "Sikeres rangadas." << endl;
    }
    else
    {
        cout << "Sikertelen rangadas." << endl;
    }
}
    

void Adminisztrator::kervenyFelulvizsgalat(const string& targy)
{
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string targy, kerveny;
            string nev = "";
            inputFile >> targy >> kerveny >> nev;
            if (nev != "" && targy != "" && kerveny != "")
            {
                cout << "A kerveny formatuma helyes, tovabbkuldve." << endl;
            }
            if(nev=="" && targy != "" && kerveny == "")
            {
                cout << "A kerveny hibas, elutasitva." << endl;
            }
            if(targy=="")
            {
                cout << "A keresett kerveny nem talalhato, elutasitva." << endl;
            }
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
            if(nev!="")
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
