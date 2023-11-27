#include "ertesites.h"

string Ertesites::uzenet = "";

Ertesites::Ertesites()
{
}

string Ertesites::getUzenet()
{
	return uzenet;
}

void Ertesites::ertesit(const string& fnev, const string &uzenet)
{
	ofstream ouputFile("uzenetek.txt");
	if (ouputFile.is_open())
	{
		while (ouputFile.eof())
		{
			string fnev = "";
			string uzenet = "";
			ouputFile << fnev << " nevu felhasznalo reszere: " << uzenet << endl;
		}
	}
	ouputFile.close();
}
