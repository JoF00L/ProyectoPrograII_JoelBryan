#pragma once
#include "Lista.h"
#include "Fecha.h"
#include <sstream>
class Curso{
private:
	string descripcion;
	int nivel;
	int cupoMax;
	//Reservas

public:
	Curso();
	Curso(string, int, int);//falta fechas y reeservas
	~Curso();
	string tipoNivel(int);
	//string horario(Fecha*, Fecha*, int, int); // podria ser una forma de trabajar el horario
	string toString();
};

