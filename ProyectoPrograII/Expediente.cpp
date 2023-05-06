#include "Expediente.h"

Expediente::Expediente() {
	inicio = new Fecha;
	ultimo = new Fecha;
	estado = true;
}

Expediente::~Expediente() {}

//------------------------------------------------------------------------------------------------------

bool Expediente::getEstado() { return estado; }
void Expediente::setEstado(bool est) { estado = est; }
Lista<Fecha>* Expediente::getHistorialPagos() { return historialPagos; }

//------------------------------------------------------------------------------------------------------

int Expediente::mesesPorPagar() {
	int meses = 0;
	Fecha* porpagar = new Fecha;
	for (int i = ultimo->getAnio(); i <= porpagar->getAnio(); i++) {
		for (int j = ultimo->getMes(); j < porpagar->getMes(); (j++, meses++));
	}
	return meses;
}

int Expediente::cuotasPorPagar(int meses, int mensualidad) { return meses * mensualidad; }

string Expediente::detallePago(int monto) { return "0"; }

Lista<Fecha>* Expediente::insertarMes(int m) {
	
	int dia = ultimo->getDia(), mes = ultimo->getMes(), anio = ultimo->getAnio();

	for (int i = 1; i <= m; i++) {	
		mes++;
		if (mes > 12) {
			anio++;
			mes = 1;
		}
	}

	ultimo = new Fecha(dia, mes, anio);
	
	historialPagos->agregar(ultimo);

	return historialPagos;
}
