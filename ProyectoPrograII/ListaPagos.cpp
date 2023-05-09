#include "ListaPagos.h"

ListaPagos::ListaPagos() { pagos = new Lista<Pago>; }

ListaPagos::~ListaPagos() { delete pagos; }

Lista<Pago>* ListaPagos::getLista() { return pagos; }

void ListaPagos::nuevoPago(Pago* nuevo) { 
	pagos->agregar(nuevo); 
}


string ListaPagos::retornaMesCancelado(){
	stringstream s;
	int mes = pagos->getNodoEsp(pagos->getSize())->getDato()->getMes();
	s << pagos->getNodoEsp(pagos->getSize())->getDato()->convierteMes(mes);
	return s.str();
}

string ListaPagos::pagosCancelados(int cuotas, int monto) {
	stringstream s;
	int anio = pagos->getNodoEsp(pagos->getSize())->getDato()->getFechaPago()->getAnio();
	int mes = pagos->getNodoEsp(pagos->getSize())->getDato()->getMes();

	s << "Se han cancelado las siguientes cuotas: " << endl << endl;
	for (int i = 0; i < cuotas; i++) {
		mes++;
		if (mes > 12) {
			anio++;
			mes = 1;
		}
		Pago* pag = new Pago(monto);
		nuevoPago(pag);
		pagos->getNodoEsp(pagos->getSize())->getDato()->setMes(mes);
		s << " -> " << pagos->getNodoEsp(pagos->getSize())->getDato()->convierteMes(mes);
		s << " " << anio << endl;
	}
	return s.str();
}

string ListaPagos::toString(){
	stringstream s;
	s << *pagos;
	return s.str();
}

void ListaPagos::guardarListaPagos(ostream& salida) {
	Nodo<Pago>* actual = pagos->getNodoEsp(0);

	while (actual != NULL) {
		if (salida.good()) {
			actual->getDato()->guardarPago(salida);
		}
		actual = actual->getSig();
	}
}

ListaPagos* ListaPagos::leerListaPagos(istream& entrada) {
	Pago* dat = NULL;
	ListaPagos* lista = new ListaPagos();
	if (entrada.good()) {
		while (!entrada.eof()) {
			dat = Pago::leerPago(entrada);
			if (dat != NULL) {
				lista->nuevoPago(dat);
			}
		}
	}
	return lista;
}