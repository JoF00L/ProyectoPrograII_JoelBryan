#pragma once
#include "Fecha.h"
#include <iostream>
#include <sstream>
using namespace std;


class Pago
{
private:
	Fecha* fechaPago;
	string mes;
	int montoDelPago;
public:
	Pago();
	Pago(Fecha* efectuado, string month, int cash);
	
};

