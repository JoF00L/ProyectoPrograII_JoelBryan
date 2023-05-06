#pragma once
#include "Lista.h"
#include"Fecha.h"
#include <sstream>
using namespace std;

class Expediente {

private:
	
	Fecha* inicio;
	Fecha* ultimo;
	bool estado;
	Lista<Fecha>* historialPagos;

public:
	Expediente();
	~Expediente();

	bool getEstado();
	void setEstado(bool);

	int mesesPorPagar();
	int cuotasPorPagar(int, int);
	string detallePago(int);

	Lista<Fecha>* getHistorialPagos();
	Lista<Fecha>* insertarMes(int);

};