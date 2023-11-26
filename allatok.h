#pragma once
#include <string>

using namespace std;

class Allatok {
private:
	string nev;
	unsigned int kor;
	string nem;
	//Rang viselkedes;
	string egeszsegugyiAllapot;
public:
	string getNev() const;
	void setNev(string& ujnev);
	unsigned int getKor() const;
	void setKor(unsigned int ujkor);
	string getNem() const;
	void setNem(string& ujnem);
	//int getViselkedes() const;
	//void setViselkedes();
	string getEgeszsegugyiAllapot() const;
	void setEgeszsegugyiAllapot(string& ujallapot);
};