#include "ugyintezo.h"
#include "allatok.h"
#include "idopontok.h"
#include "hiba.h"

int Ugyintezo::menhelyEgyenleg = 0;

void Ugyintezo::kervenyListazas()
{
    Kervenyek uj("", "");
    bool talalt = false;
    cout << "Kervenyek adatainak kilistazasa: " << endl;
    ifstream inputFile("kervenyek.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            int id;
            string fnev;
            bool elfogadva;
            inputFile >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva >> id;
            if (id > -1 && fnev != "")
            {
                cout << "A kerveny azonositoja: " << id << ", Kerveny targya: " << uj.kervenyTargy << ", Kerveny tartalma: " << uj.kerveny << ", Kervenyezo neve: " << fnev << ", Elfogadasi statusz: " << elfogadva << endl;
                talalt = true;
            }
        }
        inputFile.close();
    }
    if (!talalt)
    {
        cout << "Nem talalhato elerheto kerveny a rendszerben." << endl;
    }
}

void Ugyintezo::kervenyElfogadas(const string &fnev)
{
    kervenyListazas();
    string nev = "";
    bool sikerult = false;
    Kervenyek uj("", "");
    cout << "\nHa megsem szeretne kervenyt elbiralni, irjon be egy nullat (0)!" << endl;
    cout << "Kerem adja meg az elfogadasra szant kerveny azonositojat (szam ertekkel): ";
    int azonositoElfogadas = Hiba::intBekerHiba();
    if (azonositoElfogadas != 0) {

        ifstream inputFile("kervenyek.txt");
        ofstream outPutFile("temp.txt", ios::app);

        if (inputFile.is_open() && outPutFile.is_open())
        {
            while (!inputFile.eof())
            {
                int id;
                string fnev;
                bool elfogadva;
                inputFile >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva >> id;
                if (uj.kervenyTargy != "" && fnev != "") {
                    if (id == azonositoElfogadas)
                    {
                        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << 1 << " " << id << endl;
                        sikerult = true;
                        nev = fnev;
                    }
                    if (id != azonositoElfogadas && uj.kervenyTargy != "")
                    {
                        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << elfogadva << " " << id << endl;
                    }
                }

            }
            if (!sikerult) cout << "A kerveny nem kerult elfogadasra." << endl;
            if (sikerult) {
                cout << "\nA kerveny sikeresen elfogadasra kerult." << endl;
                Ertesitesek::ertesites(nev, uj.kervenyTargy, " A_" + uj.kervenyTargy + "_targyu_kervenye_sikeresen_elfogadasra_kerult_"+fnev+"_nevu_ugyintezo_altal.", " "+fnev);
            }
            inputFile.close();
            remove("kervenyek.txt");
            outPutFile.close();
            rename("temp.txt", "kervenyek.txt");

        }
    }
    else cout << "Kervenyelbiralas megszakitva." << endl;
}

void Ugyintezo::kervenyElutasitas(const string& fnev)
{
    kervenyListazas();
    bool sikerult = false;
    string nev = "";
    Kervenyek uj("", "");
    cout << "\nHa megsem szeretne kervenyt elbiralni, irjon be egy nullat (0)!\n" << endl;
    cout << "Kerem adja meg az elutasitasra szant kerveny azonositojat (szam ertekkel): ";
    int azonositoElutasitas = Hiba::intBekerHiba();
    if (azonositoElutasitas != 0) {
        ifstream inputFile("kervenyek.txt");
        ofstream outPutFile("temp.txt", ios::app);

        if (inputFile.is_open() && outPutFile.is_open())
        {
            while (!inputFile.eof())
            {
                int id;
                string fnev;
                bool elfogadva;
                inputFile >> uj.kervenyTargy >> uj.kerveny >> fnev >> elfogadva >> id;
                if (uj.kervenyTargy != "" && fnev != "") {
                    if (id == azonositoElutasitas)
                    {
                        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << 0 << " " << id << endl;
                        sikerult = true;
                        nev = fnev;
                    }
                    if (id != azonositoElutasitas)
                    {
                        outPutFile << uj.kervenyTargy << " " << uj.kerveny << " " << fnev << " " << elfogadva << " " << id << endl;

                    }
                }
            }
            if (!sikerult) cout << "A kerveny nem kerult elutasitasra." << endl;
            if (sikerult) {
                cout << "\nA kerveny elutasitasra kerult." << endl;
                Ertesitesek::ertesites(nev, uj.kervenyTargy, " A_" + uj.kervenyTargy + "_targyu_kervenye_elutasitasra_kerult_"+fnev + "_nevu_ugyintezo_altal.", " "+fnev);
            }
            inputFile.close();
            remove("kervenyek.txt");
            outPutFile.close();
            rename("temp.txt", "kervenyek.txt");
        }
    }
    else cout << "Kervenyelbiralas megszakitva." << endl;
}

void Ugyintezo::addSetaltatasIdopont()
{
    cout << "A menhely allatai: " << endl;
    RegisztraltFelhasznalo::allatokKilistaz();
    cout << endl;
    string nev;
    string foglalo = "ures";
    int ev, honap, nap, ora;
    cout << "\nHa megsem szeretne idopontot hozzadni, irjon be egy nullat." << endl;
    cout << "Melyik allatnak szeretne idopontot feltolteni setaltatasra?: ";
    cin >> nev;
    if (nev != "0") {
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
    else cout << "Idopont hozzaadas megszakitva." << endl;
}

void Ugyintezo::addOnkentesIdopont()
{
    cout << "Onkenteskedes idopontok reszleteire peldak: " << endl;
    onkenteskedesListazas();

    string nev;
    string foglalo = "senki";
    cout << "\nHa megsem szeretne idopontot hozzadni, irjon be egy nullat." << endl;
    cout << "Milyen onkentes tevekenysegre szeretne idopontot letrehozni? (szokoz eseten (_) alulvonast hasznaljon!): ";
    cin >> nev;
    if (nev != "0") {
        cout << "\nIrja be a datumot szokozokkel elvalasztva (ev honap nap ora): ";
        int ev = Hiba::intBekerHiba();
        int honap = Hiba::intBekerHiba();
        int nap = Hiba::intBekerHiba();
        int ora = Hiba::intBekerHiba();
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
    else cout << "Idopont hozzaadas megszakitva." << endl;
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
                cout << "Allat neve: " << nev << ", ev: " << ev << ", honap: " << honap << ", nap: " << nap << ", ora: " << ora << ", lefoglalo: " << foglalo << endl;
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
                cout << "Tevekenyseg: " << tevekenyseg << ", ev: " << ev << ", honap: " << honap << ", nap: " << nap << ", ora: " << ora << ", lefoglalo: " << felhasznalo << endl;
            }
        }

    }
    inputFile.close();
}


void Ugyintezo::setMenhelyEgyenleg()
{
    bool lefut = false;
    ifstream inputFile("felhasznalok.txt");
    ofstream outputFile("temp.txt", ios::app);

    cout << "Az menhely aktualis egyenlege: " << Egyenleg::getMenhelyEgyenleg() << " Ft.\n" << endl;
    cout << "Kerem adja meg a menhely egyenlegere feltolteni kivant osszeget: ";
    int osszeg = Hiba::intBekerHiba();

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
        if (lefut) cout << "Sikeres menhely egyenlegfeltoltes, az uj egyenleg: " << Egyenleg::getMenhelyEgyenleg()+osszeg << " Ft." << endl;
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

    cout << "A menhely aktualis egyenlege: " << Egyenleg::getMenhelyEgyenleg() << " Ft.\n" << endl;
    cout << "Ha megsem szeretne feltolteni a keszletet, irjon be egy nullat (0)!" << endl;
    cout << "Kerem adja meg a keszlet feltoltesere szant osszeget: ";
    int osszeg = Hiba::intBekerHiba();

    ifstream inputFile("felhasznalok.txt");
    ofstream outputFile("temp.txt", ios::app);

    if (osszeg != 0  && egyUgyintezoVan() && osszeg <= Egyenleg::getMenhelyEgyenleg())
    {
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
                        outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye - osszeg << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    }

                    else
                    {
                        outputFile << nev << " " << jelszo << " " << szerep << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << " " << figyelmeztetes << endl;
                    
                    }
                }
            }
            inputFile.close();
            remove("felhasznalok.txt");
            outputFile.close();
            rename("temp.txt", "felhasznalok.txt");
        }
    }
    if(osszeg==0)
    {
        cout << "\nKeszletfeltoltes megszakitva!" << endl;
    }
    else if (!egyUgyintezoVan())
    {
        cout << "\nAz ugyintezok szama meghaladja a korlatot!" << endl;
    }
    else if (lefut)
    {
        cout << "\nSikeres keszletfeltoltes!" << endl;
        cout << "Uj egyenleg: " << Egyenleg::getMenhelyEgyenleg() << " Ft." << endl;
    }
    else
    {
        Hiba::folyositasiHiba();
        Hiba::folyositasiHibaleiras();
    }
}
