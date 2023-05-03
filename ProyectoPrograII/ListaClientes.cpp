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

string ListaClientes::toString() {
	stringstream s; 
	s << *customers << endl;
	return s.str();
}

//Agregue el toString() commo extra porque por la forma en la que hice la lista podemos llamarlo 
//de otra forma: cout << *ListaClientes->getLista() << endl