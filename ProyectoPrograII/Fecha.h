#pragma once
#include <ctime>
#include <sstream>
#include <iostream>
#include "ManejoArchivos.h"
#pragma warning(disable:4996)
#define max 3
using namespace std;

class Fecha {
private:

	int dia;
	int mes;
	int anio;

public:

	Fecha();
	Fecha(int, int, int);
	~Fecha();
	//--------------------------------------------
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	int getDia();
	int getMes();
	int getAnio();
	//--------------------------------------------
	string diferenciaFechas(Fecha*);
	bool esMenor(Fecha*);
	int devuelveEdad(Fecha*);
	//--------------------------------------------
	string toString() const;
	//--------------------------------------------
	void guardarFecha(ostream& salida);
	static Fecha* leerFecha(istream& entrada);
};

ostream& operator<<(ostream& output, const Fecha& data);