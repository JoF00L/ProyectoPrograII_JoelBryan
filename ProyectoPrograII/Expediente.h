#pragma once
#include "Lista.h"
#include <sstream>
class Expediente{
private:
	bool activo;//no estoy seguro si esto es un atributo o metodo
	//faltan datos, me imagino que son fechas
public:
	Expediente();
	Expediente(bool);
	~Expediente();
	string toString();
};

