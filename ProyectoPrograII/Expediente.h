#pragma once
#include "Lista.h"
#include <sstream>
#include"Fecha.h"

class Expediente {
private:
	Fecha* inicio;
	Fecha* ultimo;
	bool estado;
	//Clase tipo lista fecha

public:
	Expediente();
	~Expediente();

	bool getEstado();
	void setEstado(bool);

	int mesesPorPagar();
	double cuotasPorPagar(int, double);
	string detallePago(double);

	Lista<Fecha>* getHistorialPagos();
	Lista<Fecha>* insertarMeses(int);

};