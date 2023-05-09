#include "ListaClientes.h"

ListaClientes::ListaClientes() { customers = new Lista<Cliente>; }

ListaClientes::~ListaClientes() { delete customers; }

//-----------------------------------------------------------------------------------------------------

Lista<Cliente>* ListaClientes::getLista() { return customers; }

//-----------------------------------------------------------------------------------------------------

void ListaClientes::agregarCliente(Cliente* newClient) { customers->agregar(newClient); }

//-----------------------------------------------------------------------------------------------------

void ListaClientes::eliminarCliente(string ID) {
	int borrar = 0;
	if (customers->getNodoEsp(0)->getDato()->getCedula() == ID) {
		customers->eliminarPos(0);
		return;
	}
	while (customers->getNodoEsp(borrar)->getDato()->getCedula() != ID) {
		borrar++;
	}
	customers->eliminarPos(borrar);
}

Cliente* ListaClientes::getClienteEsp(string ID) {
	int buscar = 0;
	if (customers->getNodoEsp(0)->getDato()->getCedula() == ID) {
		return customers->getNodoEsp(0)->getDato();
	}
	while (customers->getNodoEsp(buscar)->getDato()->getCedula() != ID) {
		buscar++;
	}
	return customers->getNodoEsp(buscar)->getDato();
}

//-----------------------------------------------------------------------------------------------------

string ListaClientes::Activos() {
	stringstream s;
	for (int i = 0; i < customers->getSize(); i++) {
		if (customers->getNodoEsp(i)->getDato()->getEstado() == 1) {
			s << *customers->getNodoEsp(i) << endl;
		}
	}
	return s.str();
}

string ListaClientes::Inactivos() {
	stringstream s;
	for (int i = 0; i < customers->getSize(); i++) {
		if (customers->getNodoEsp(i)->getDato()->getEstado() == 2) {
			s << *customers->getNodoEsp(i) << endl;
		}
	}
	return s.str();
}

void ListaClientes::setMorosos() {
	Fecha* actual = new Fecha;
	for (int i = 0; i < customers->getSize(); i++) {
		if (customers->getNodoEsp(i)->getDato()->getListaPagos()->getLista()->getNodoEsp(customers->getNodoEsp(i)->getDato()->getListaPagos()->getLista()->getSize())->getDato()->getMes() < actual->getMes()) {
			customers->getNodoEsp(i)->getDato()->setEstado(3);
		}
	}
}

string ListaClientes::Morosos() {
	stringstream s;
	for (int i = 0; i < customers->getSize(); i++) {
		if (customers->getNodoEsp(i)->getDato()->getEstado() == 3) {
			s << *customers->getNodoEsp(i) << endl;
		}
	}
	return s.str();
}

//-----------------------------------------------------------------------------------------------------

string ListaClientes::toString() {
	stringstream s; 
	s << *customers << endl;
	return s.str();
}

string ListaClientes::sencilloClientes() {
	stringstream s;
	for (int i = 0; i < customers->getSize(); i++) {
		s << customers->getNodoEsp(i)->getDato()->getCedula() << " - " << customers->getNodoEsp(i)->getDato()->getNombre() << endl;
	}
	return s.str();
}

void ListaClientes::enviaArchivoList(ostream& salida){
	Nodo<Cliente>* actual = customers->getNodoEsp(0);

	while (actual != NULL) {
		if (salida.good()) {
			actual->getDato()->guardarCliente(salida);
		}
		actual = actual->getSig();
	}
}

ListaClientes* ListaClientes::recuperaArchivoList(istream& entrada){
	Cliente* dat = NULL;
	ListaClientes* lista = new ListaClientes();
	if (entrada.good()) {
		while (!entrada.eof()) {
			dat = Cliente::leerCliente(entrada);
			if (dat != NULL) {
				lista->getLista()->agregar(dat);
			}
		}
	}
	return lista;
}

void ListaClientes::guardarListaClientes(){
	ofstream salida;
	Nodo<Cliente>* actual = customers->getNodoEsp(0);

	salida.open("../ListaClientes.txt");
	while (actual != NULL)
	{
		if (salida.good()) {
			actual->getDato()->guardarCliente(salida);
		}
		actual = actual->getSig();
	}
	salida.close();
}

void ListaClientes::leerListaClientes(){
	ifstream entrada; 
	Cliente* client; 
	entrada.open("../ListaClientes.txt");

	if (entrada.good()) {
		while (!entrada.eof()) {
			client = Cliente::leerCliente(entrada);
			if (client != nullptr) {
				customers->agregar(client);
			}
		}
	}
	entrada.close();
}
