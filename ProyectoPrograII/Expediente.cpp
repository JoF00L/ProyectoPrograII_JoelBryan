#include "Expediente.h"

Expediente::Expediente() {
	inicio = Fecha::getFechaActual();
	ultimo = Fecha::getFechaActual();
	estado = true;
}
Expediente::~Expediente() {}

bool Expediente::getEstado() { return estado; }
void Expediente::setEstado(bool est) { estado = est; }

int Expediente::mesesPorPagar() {
	int meses = 0;

	for (int i = ultimo->getAnio(); i <= Fecha::getFechaActual()->getAnio(); i++) {
		for (int j = ultimo->getMes(); j < Fecha::getFechaActual()->getMes(); (j++, meses++));
	}
	return meses;

}
double Expediente::cuotasPorPagar(int meses, double mensualidad) {
	return meses * mensualidad;
}
string Expediente::detallePago(double monto) {
	//Este metodo lo trabajamos despues
	return 0;
}

Lista<Fecha>* Expediente::getHistorialPagos() { return 0; }
Lista<Fecha>* Expediente::insertarMeses(int m) {
	/*int dia = ultimo->getDia(), mes = ultimo->getMes(), anio = ultimo->getAnio();
	Lista<Fecha>* lista = new Lista<Fecha>();
	Fecha* aux = NULL;

	for (int i = 1; i <= m; i++) {
		mes++;

		if (mes > 12) {
			anio++;
			mes = 1;
		}
		ultimo = new Fecha(dia, mes, anio);
		lista->agregar(new Fecha(dia, mes, anio));

		historialPagos->agregar(ultimo);
	}
	return lista;*/

	return 0;
}
