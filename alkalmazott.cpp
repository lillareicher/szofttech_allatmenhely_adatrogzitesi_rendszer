#include "alkalmazott.h"

void Alkalmazott::addFelhasznaloFigyelmeztetes(const string& felhasznalo)
{
}

void Alkalmazott::keszletFeltoltesiIgeny()
{
}

void Alkalmazott::adatFeltoltes(const string& allatnev)
{
}

void Alkalmazott::rangNoveles(const string& felhasznalo, int osszeg) //? 
{
	ifstream inputFile("felhasznalok.txt");
	ofstream outputFile("tmp.txt", ios::app);
	if (inputFile.is_open() && outputFile.is_open())
	{
		while (!inputFile.eof())
		{
			string nev = "";
			string jelszo;
			int szerepkor, rang, egyenleg, menhelye, rangSzamlalo;
			inputFile >> nev >> jelszo >> szerepkor >> rang >> egyenleg >> menhelye >> rangSzamlalo;
			if (nev != "" && nev == felhasznalo && osszeg!=0)
			{
				outputFile << nev << " " << jelszo << " " << szerepkor << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo + osszeg << endl;
			}
			else
			{
				outputFile << nev << " " << jelszo << " " << szerepkor << " " << rang << " " << egyenleg << " " << menhelye << " " << rangSzamlalo << endl;
			}
		}
		inputFile.close();
		remove("felhasznalok.txt");
		outputFile.close();
		rename("tmp.txt", "felhasznalok.txt");
	}
	cout << "Sikeres rangszamlalo noveles." << endl;
}
