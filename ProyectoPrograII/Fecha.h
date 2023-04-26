#pragma once
#include <ctime>
#include <sstream>
#include <iostream>
#pragma warning(disable:4996)
#define max 3
using namespace std;

class Fecha {
private:
	
	int fecha[max];

public:

	Fecha();
	Fecha(int, int, int);
	string diferenciaFechas(Fecha*);
	bool esMenor(Fecha*);
	int devuelveEdad(Fecha*);
	string toString();
	~Fecha();
};

