#include "ugyintezo.h"
#include "ertesites.h"
#include "allatok.h"
#include "idopontok.h"

int Ugyintezo::menhelyEgyenleg = 0;

void Ugyintezo::kervenyListazas()
{
    Kervenyek uj("", "");
    cout << "Kervenyek adatainak kilistazasa: " << endl;
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            int id;
            string fnev;
            bool elfogadva;
            inputFile >> id >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva;
            if (id>-1 /*&& fnev!=""*/)
            {
                cout << "A kerveny azonositoja: " << id << ", Kerveny targya: " << uj.kervenyTargy << ", Kerveny tartalma: " << uj.kerveny << ", Kervenyezo neve: " << fnev << "Elfogadasi statusz: " << elfogadva << endl;
            }
            else
            {
                cout << "Nem talalhato elerheto kerveny a rendszerben." << endl;
            }
        }
        inputFile.close();
    }
}

void Ugyintezo::kervenyElfogadas()
{
    kervenyListazas();
    bool sikerult = false;
    Kervenyek uj("", "");
    int azonositoElfogadas;
    cout << "Kerem adja meg az elfogadasra szant kerveny azonositojat (szam ertekkel): ";
    cin >> azonositoElfogadas;

    ifstream inputFile("kervenyek.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (inputFile.is_open() && outPutFile.is_open())
    {
        while (!inputFile.eof())
        {
            int id;
            string fnev;
            bool elfogadva;
            inputFile >> id >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva;
            if (id == azonositoElfogadas)
            {
                outPutFile << id << " " << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << 1 << endl;
                cout << "\nA kerveny sikeresen elfogadasra kerult." << endl;
                Ertesites::ertesites(fnev, uj.kervenyTargy, "A_" + uj.kervenyTargy + "_targyu_kervenye_sikeresen_elfogadasra_kerult.");
                sikerult = true;
            }
            if (id != azonositoElfogadas)
            {
                outPutFile << id << " " << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << elfogadva << endl;
            }

        }
        if(!sikerult) cout << "A kerveny nem kerult elfogadasra." << endl;
        inputFile.close();
        remove("kervenyek.txt");
        outPutFile.close();
        rename("temp.txt", "kervenyek.txt");

    }
}

void Ugyintezo::kervenyElutasitas()
{
    kervenyListazas();
    bool sikerult = false;
    Kervenyek uj("", "");
    int azonositoElutasitas;
    cout << "Kerem adja meg az elfogadasra szant kerveny azonositojat (szam ertekkel): ";
    cin >> azonositoElutasitas;

    ifstream inputFile("kervenyek.txt");
    ofstream outPutFile("temp.txt", ios::app);

    if (inputFile.is_open() && outPutFile.is_open())
    {
        while (!inputFile.eof())
        {
            int id;
            string fnev;
            bool elfogadva;
            inputFile >> id >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva;
            if (id == azonositoElutasitas && elfogadva != 1)
            {
                outPutFile << id << " " << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << 0 << endl;
                cout << "\nA kerveny elutasitasra kerult." << endl;
                Ertesites::ertesites(fnev, uj.kervenyTargy, "A_" + uj.kervenyTargy + "_targyu_kervenye_elutasitasra_kerult.");
                sikerult = true;
            }
            if (id != azonositoElutasitas)
            {
                outPutFile << id << " " << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << elfogadva << endl;

            }
        }
        if(!sikerult) cout << "A kerveny nem kerult elutasitasra." << endl;
        inputFile.close();
        remove("kervenyek.txt");
        outPutFile.close();
        rename("temp.txt", "kervenyek.txt");
    }
}

void Ugyintezo::addSetaltatasIdopont()
{
    cout << "A menhely allatai: " << endl;
    RegisztraltFelhasznalo::allatokKilistaz();
    cout << endl;
    string nev;
    string foglalo = "ures";
    int ev, honap, nap, ora;
    cout << "\nMelyik allatnak szeretne idopontot feltolteni setaltatasra?: ";
    cin >> nev;
    if (Allatok::allatVan(nev) == true) {
        cout << "\nIrja be a datumot szokozokkel elvalasztva (ev honap nap ora): ";
        cin >> ev >> honap >> nap >> ora;
        if (Idopontok::validDatum(ev, honap, nap, ora))
        {
            ofstream outputFile("allatFoglalt.txt", ios::app);
            if (outputFile.is_open()) {
                outputFile << nev << " " << ev << " " << honap << " " << nap << " " << ora << " " << 0 << " " << foglalo << endl;
            }
            outputFile.close();
            cout << "Sikeres idopontbeallitas! " << endl;
        }
        else {
            cout << "Nem megfelelo a datum." << endl;
        }
    }
    else {
        cout << "Nincs ilyen allat a menhelyen, visszalepes az opciokhoz." << endl;
    }
}

void Ugyintezo::addOnkentesIdopont()
{
    cout << "Onkenteskedes idopontok reszleteire peldak: " << endl;
    onkenteskedesListazas();

    string nev;
    string foglalo = "senki";
    int ev, honap, nap, ora;
    cout << "\nMilyen onkentes tevekenysegre szeretne idopontot letrehozni? (szokoz eseten (_) alulvonast hasznaljon!): ";
    cin >> nev;
    cout << "\nIrja be a datumot szokozokkel elvalasztva (ev honap nap ora): ";
    cin >> ev >> honap >> nap >> ora;
    if (Idopontok::validDatum(ev, honap, nap, ora))
    {
        ofstream outputFile("foglalasok.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << nev << " " << ev << " " << honap << " " << nap << " " << ora << " " << foglalo << endl;
        }
        outputFile.close();
        cout << "Sikeres onkentes tevekenyseg hozzaadas. " << endl;
    }
    else {
        cout << "Nem megfelelo a datum. " << endl;

    }
}

void Ugyintezo::setaltatasokListazas()
{
    ifstream inputFile("allatFoglalt.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string nev, foglalo;
            int ev, honap, nap, ora;
            bool foglalt;
            inputFile >> nev >> ev >> honap >> nap >> ora >> foglalt >> foglalo;
            if (nev != "") {
                cout << "Nev: " << nev << ", ev: " << ev << ", honap: " << honap << ", nap: " << nap << ", ora: " << ora << ", Vallalta: " << foglalo << endl;
            }
        }

    }
    inputFile.close();
}

void Ugyintezo::onkenteskedesListazas()
{
    ifstream inputFile("foglalasok.txt");
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            string felhasznalo, tevekenyseg;
            int ev, honap, nap, ora;
            inputFile >> tevekenyseg >> ev >> honap >> nap >> ora >> felhasznalo;
            if (tevekenyseg != "") {
                cout << "Tevekenyseg: " << tevekenyseg << " ev: " << ev << " honap: " << honap << " nap: " << nap << " ora: " << ora << " lefoglalta eddig: " << felhasznalo << endl;
            }
        }

    }
    inputFile.close();
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
            if (nev != "")
            {
                if (szerep == 2)
                {
                    lefut = true;
                    outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye + osszeg << " " << rangSzamlalo << " " << figyelmeztetes << endl;
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
        if (lefut) cout << "Sikeres keszletfeltoltes." << endl;
        else cout << "Sikertelen keszletfeltoltes." << endl;

        inputFile.close();
        remove("felhasznalok.txt");
        outputFile.close();
        rename("temp.txt", "felhasznalok.txt");
    }
}
