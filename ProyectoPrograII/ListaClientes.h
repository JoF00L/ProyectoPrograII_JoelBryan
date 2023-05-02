#pragma once
#include "Clientes.h"
#include "Lista.h"
class ListaClientes
{
private:

	Lista<Cliente>* customers;

public:

	ListaClientes();
	~ListaClientes();
	//--------------------------------------------
	Lista<Cliente>* getLista();
	void agregar(Cliente* nuevo);
	void eliminarEsp(string ID);
	Cliente* getClienteEsp(string ID);
	//--------------------------------------------
	string toString();
};
