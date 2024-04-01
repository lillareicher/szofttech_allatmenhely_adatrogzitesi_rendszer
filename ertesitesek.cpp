#include "ertesitesek.h"

Ertesitesek::Ertesitesek()
{
}

void Ertesitesek::ertesites(const string& nev, const string& targy, const string &ertesites, const string& kuldonev)
{
	ofstream outputFile("ertesitesek.txt", ios::app);

	if (outputFile.is_open())
	{
		outputFile << nev << " " << targy << " " << ertesites << kuldonev << endl;
	}

	outputFile.close();
	cout << "\nErtesites sikeresen elkuldve!" << endl;
}

void Ertesitesek::ertesitesLekeres(const string& fnev)
{
	cout << endl;
	ifstream inputFile("ertesitesek.txt");
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			string nev = "";
			string targy = "";
			string ertesites = "";
			string kuldonev = "";
			inputFile >> nev >> targy >> ertesites >> kuldonev;
			if (nev == fnev)
			{
				string input_str = ertesites;
				string regex_str = "_";
				auto tokens = stringFeldarabolas(input_str, regex_str);
				for (auto& item : tokens)
				{
					cout << item << " ";
				}
				cout << endl;
			}
		}
		inputFile.close();
		cout << "\nErtesitesek sikeres kilistazasa." << endl;
	}
}

vector<string> Ertesitesek::stringFeldarabolas(const string str, const string regex_str)
{
	regex regexz(regex_str);
	return { sregex_token_iterator(str.begin(), str.end(), regexz, -1), sregex_token_iterator() };

}

