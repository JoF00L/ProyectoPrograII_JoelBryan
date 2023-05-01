#pragma once
#include "Fecha.h"
#define maxDias 7
#define horas 2

class Horario{
private:
	Fecha* inicio;
	Fecha* fin;
	int dias[maxDias];
	int cantidad;
	int hora[horas];
public:
	Horario(Fecha*,Fecha*);
	~Horario();
	string convierteDia(int d);
	void agregaDias(int d);
	void agregaHoras(int h, int m);
	string toString();
};

