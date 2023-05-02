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
	int dia;
	int mes;
	int anio;

public:

	Fecha();
	Fecha(int, int, int);
	~Fecha();
	//--------------------------------------------
	int getDia();
	int getMes();
	int getAnio();

	void setDia(int);
	void setMes(int);
	void setAnio(int);

	string diferenciaFechas(Fecha*);
	bool esMenor(Fecha*);
	int devuelveEdad(Fecha*);

	static Fecha* getFechaActual();
	//--------------------------------------------
	string toString();
	string normalizarMes();
};

