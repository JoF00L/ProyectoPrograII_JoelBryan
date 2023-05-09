#pragma once
#include "Pago.h"
#include "Lista.h"

class ListaPagos
{
private:
	
	Lista<Pago>* pagos;

public:

	ListaPagos();
	~ListaPagos();
	//--------------------------------------------
	Lista<Pago>* getLista();
	void nuevoPago(Pago* nuevo);
	/*void seteaPagos();
	void eliminarPagos();*/
	//--------------------------------------------
	string retornaMesCancelado();
	string pagosCancelados(int cuotas, int monto);
	string toString();
	
};

