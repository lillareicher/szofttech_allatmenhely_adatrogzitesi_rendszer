#include "ertesites.h"

string Ertesites::uzi = "";

Ertesites::Ertesites()
{
}

string Ertesites::getUzenet()
{
	return uzi;
}

void Ertesites::uzenet()
{
	string nev="";
	string uzen="";
	cout << "Kerem adja meg a felhasznalo nevet aki szamara ertesitest szeretne kuldeni:\n";
	cin >> nev;
	cout << "Kerem adja meg a uzenet szoveget (a szavakat kotojellel valassza el): \n";
	cin >> uzen;
	
	ofstream outputFile("uzenetek.txt", ios::app);

	if (outputFile.is_open())
	{
		outputFile << nev << " " << uzen << endl;
	}
	
	outputFile.close();
	cout << "Ertesites sikeres elkuldese" << endl;
}

void Ertesites::uzenetLekeres(const string& fnev)
{
	ifstream inputFile("uzenetek.txt");
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			string nev = "";
			string uzenet = "";
			inputFile >> nev >> uzenet;
			if (nev == fnev)
			{
				cout << uzenet << endl;
			}
		}
		inputFile.close();
		cout << "\nUzenetek sikeres kilistazasa." << endl;
	}
}

void Ertesites::ertesites(const string& nev, const string& targy, const string &ertesites)
{
	ofstream outputFile("ertesitesek.txt", ios::app);

	if (outputFile.is_open())
	{
		outputFile << nev << " " << targy << " " << ertesites << endl;
	}

	outputFile.close();
	cout << "\nErtesites sikeresen elkuldve!" << endl;

}

void Ertesites::ertesitesLekeres(const string& fnev)
{
	ifstream inputFile("ertesitesek.txt");
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			string nev = "";
			string targy = "";
			string ertesites = "";
			inputFile >> nev >> targy >> ertesites;
			if (nev == fnev)
			{
				cout << ertesites << endl;
			}
		}
		inputFile.close();
		cout << "\nErtesitesek sikeres kilistazasa." << endl;
	}
}

