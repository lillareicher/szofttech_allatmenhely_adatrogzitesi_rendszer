#pragma once
#include <string>
#include <vector>
using namespace std;

class Idopontok {
private:
	vector<string> szabadIdopontok;
	int ev;
	int honap;
	int nap;
	int ora;
public:
	Idopontok();
	Idopontok(int _ev, int _honap, int _nap, int _ora);
	int getDatum() const;
};