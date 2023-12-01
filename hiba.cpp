#include "hiba.h"
#define _CRT_NO_SECURE_WARNINGS_GLOBAL

void Hiba::folyositasiHiba()
{
	ofstream outputFile("folyositasihiba.txt");

	if (outputFile.is_open())
	{
		string msg = "Hibas_tranzakcio";
		outputFile << msg << endl;
	}
	outputFile.close();
}

void Hiba::folyositasiHibaleiras()
{
	ifstream inputFile("folyositasihiba.txt");

	if (inputFile.is_open())
	{
		string msg;
		time_t raw_time;
		time(&raw_time);
		struct tm local_time;
		localtime_s(&local_time, &raw_time);
		inputFile >> msg;
		if (msg != "")
		{
			cout << "Rendszeruzenet: " << msg << ", idopont: " << put_time(&local_time, "%F %T") << endl;
		}
	}
	inputFile.close();
}
