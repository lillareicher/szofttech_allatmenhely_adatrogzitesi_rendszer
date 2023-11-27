#pragma once
#include <string>

#include "rang.h"

using namespace std;

class Allatok {
private:
	string nev;
	unsigned int kor;
	string nem;
	Rang kezelhetoseg;
	string egeszsegugyiAllapot;
public:
	string getNev() const;
	void setNev(string& ujnev);
	unsigned int getKor() const;
	void setKor(unsigned int ujkor);
	string getNem() const;
	void setNem(string& ujnem);
	Rang getKezelhetoseg() const;
	void setKezelhetoseg(const Rang &k);
	string getEgeszsegugyiAllapot() const;
	void setEgeszsegugyiAllapot(string& ujallapot);
};