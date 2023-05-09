#pragma once
#include "Fecha.h"
#include <iostream>
#include <sstream>
using namespace std;


class Pago
{
private:
	Fecha* fechaPago;
	int mes;
	int monto;
public:
	Pago(int costo);
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
	//string pagosCancelados(int cuotas, int montoMensualidad);
	string toString() const;
};

ostream& operator<<(ostream& output, const Pago& p);
