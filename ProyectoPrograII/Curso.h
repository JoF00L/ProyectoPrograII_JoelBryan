#pragma once
#include "Lista.h"
#include <sstream>
class Curso{
private:
	string descripcion;
	int nivel;
	//Fechas y horario del curso
	int cupoMax;
	//Reservas

public:
	Curso();
	Curso(string, int, int);//falta fechas y reeservas
	~Curso();
	string tipoNivel(int);
	string toString();
};

