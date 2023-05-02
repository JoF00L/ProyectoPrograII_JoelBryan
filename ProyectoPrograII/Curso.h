#pragma once
#include "Lista.h"
#include "Fecha.h"
#include <sstream>
class Curso{
private:
	string descripcion;
	int nivel;
	int cupoMax;
	//lista de clientes

public:
	Curso();
	Curso(string, int, int);//falta fechas y reeservas
	~Curso();
	string tipoNivel(int);
	string toString();
};

