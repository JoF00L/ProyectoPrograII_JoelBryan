#pragma once
#define max 3
#include <ctime>
#include <sstream>
#include <iostream>
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

