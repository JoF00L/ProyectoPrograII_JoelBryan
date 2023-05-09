#pragma once
#include "Fecha.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;


class Pago
{
private:
	Fecha* fechaPago;
	int mes;
	int monto;
public:
	Pago(int costo);
	Pago(Fecha* fechaNueva, int nuevoMes, int costo);
	~Pago();
	//--------------------------------------------
	void setMes(int nuevoMes);
	void setMonto(int costo);
	//--------------------------------------------
	Fecha* getFechaPago();
	int getMes();
	int getMonto();
	//--------------------------------------------
	string convierteMes(int mes) const;
	string toString() const;
	//--------------------------------------------
	void guardarPago(ostream& salida);
	static Pago* leerPago(istream& entrada);
};

ostream& operator<<(ostream& output, const Pago& p);
