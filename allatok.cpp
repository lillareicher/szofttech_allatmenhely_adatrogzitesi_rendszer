#include "allatok.h"




string Allatok::getNev() const {
	return nev;
};

void Allatok::setNev(string& ujnev) {
	nev = ujnev;
}

unsigned int Allatok::getKor() const {
	return kor;
}

void Allatok::setKor(unsigned int ujkor) {
	kor = ujkor;

}

string Allatok::getNem() const {
	return nem;
}

void Allatok::setNem(string& ujnem) {
	nem = ujnem;
}

Rang Allatok::getKezelhetoseg() const
{
	return kezelhetoseg;
}

void Allatok::setKezelhetoseg(const Rang &k)
{
}



string Allatok::getEgeszsegugyiAllapot() const {
	return egeszsegugyiAllapot;
}

void Allatok::setEgeszsegugyiAllapot(string& ujallapot) {
	egeszsegugyiAllapot = ujallapot;
}