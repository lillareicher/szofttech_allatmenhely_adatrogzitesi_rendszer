#include "ugyintezo.h"

int Ugyintezo::menhelyEgyenleg = 0;

void Ugyintezo::kervenyListazas()
{
    cout << "Kervenyek adatainak kilistazasa: " << endl;
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            string kervenyTargy = "";
            string kerveny = "";
            string nev = "";
            bool elfogadva;
            inputFile >> kervenyTargy >> kerveny >> nev >> elfogadva;
            if (kervenyTargy != "" && kerveny!="" && nev!="")
            {
                cout << "Kerveny targya: " << kervenyTargy << ", Kerveny tartalma: " << kerveny << ", Kervenyezo neve: " << nev << endl;
            }
        }
        inputFile.close();
    }
}

void Ugyintezo::kervenyElfogadas()
{
    kervenyListazas();
    
    string targyElfogadas;
    cout << "Kerem adja meg az elfogadasra szant kerveny targyat: ";
    cin >> targyElfogadas;

    ifstream inputFile("kervenyek.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (inputFile.is_open() && outPutFile.is_open())
    {
        while (!inputFile.eof())
        {
            string kervenyTargy, kerveny, nev;
            bool elfogadva;
            inputFile >> kervenyTargy >> kerveny >> nev >> elfogadva;
            if (kervenyTargy == targyElfogadas && elfogadva!=1)
            {
                outPutFile << kervenyTargy << " " << kerveny << " " << nev << " " << 1 << endl;
                cout << "\nA kerveny sikeresen elfogadasra kerult." << endl;
                Ertesites::ertesites(nev, kervenyTargy, "A_"+kervenyTargy+"_targyu_kervenye_sikeresen_elfogadasra_kerult.");            
            }
            if(kervenyTargy!=targyElfogadas && elfogadva==1)
            {
                outPutFile << kervenyTargy << " " << kerveny << " " << nev << " " << 0 << endl;
                cout << "A kerveny nem kerult elfogadasra." << endl;    
            }
        }
        inputFile.close();
        remove("kervenyek.txt");
        outPutFile.close();
        rename("temp.txt", "kervenyek.txt");
        
    }
}

void Ugyintezo::kervenyElutasitas()
{
    kervenyListazas();

    string targyElutasitas;
    cout << "Kerem adja meg az elfogadasra szant kerveny targyat: ";
    cin >> targyElutasitas;

    ifstream inputFile("kervenyek.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (inputFile.is_open() && outPutFile.is_open())
    {
        while (!inputFile.eof())
        {
            string kervenyTargy, kerveny, nev;
            bool elfogadva;
            inputFile >> kervenyTargy >> kerveny >> nev >> elfogadva;
            if (kervenyTargy == targyElutasitas && elfogadva != 1)
            {
                outPutFile << kervenyTargy << " " << kerveny << " " << nev << " " << 0 << endl;
                cout << "\nA kerveny elutasitasra kerult." << endl;
                Ertesites::ertesites(nev, kervenyTargy, "A_" + kervenyTargy + "_targyu_kervenye_elutasitasra_kerult.");
            }
            if (kervenyTargy != targyElutasitas && elfogadva == 1)
            {
                outPutFile << kervenyTargy << " " << kerveny << " " << nev << " " << 1 << endl;
                cout << "A kerveny nem kerult elutasitasra." << endl;
            }
        }
        inputFile.close();
        remove("kervenyek.txt");
        outPutFile.close();
        rename("temp.txt", "kervenyek.txt");
    }
}

void Ugyintezo::addIdopont()
{
}



void Ugyintezo::setMenhelyEgyenleg()
{
    bool lefut = false;
    int osszeg = 0;
    ifstream inputFile("felhasznalok.txt");
    ofstream outputFile("temp.txt", ios::app);

    cout << "Kerem adja meg a menhely szamara feltolteni kivant osszeget: ";
    cin >> osszeg;

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
                if (szerep == 2)
                {
                    lefut = true;
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye+osszeg << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
                else
                {
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
            }
        }
        if (lefut) cout << "Sikeres menhely egyenlegfeltoltes, az uj egyenleg: " << endl;
        else cout << "Sikertelen menhely egyenlegfeltoltes." << endl;

        inputFile.close();
        remove("felhasznalok.txt");
        outputFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }
}

void Ugyintezo::keszletFeltoltes()
{
    bool lefut = false;
    int osszeg;
    cout << "Kerem adja meg a keszlet feltoltesere szant osszeget: ";
    cin >> osszeg;

    ifstream inputFile("felhasznalok.txt");
    ofstream outputFile("temp.txt", ios::app);

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
                if (szerep == 2)
                { 
                    lefut = true;
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg - osszeg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
                else
                {
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                }
            }
        }
        if (lefut) cout << "Sikeres keszletfeltoltes, az uj egyenleg: " <<  endl;
        else cout << "Sikertelen keszletfeltoltes." << endl;
            
        inputFile.close();
        remove("felhasznalok.txt");
        outputFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }
}

