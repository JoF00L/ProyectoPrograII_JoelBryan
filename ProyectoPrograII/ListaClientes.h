#pragma once
#include "Clientes.h"
#include "Lista.h"
#include "Excepciones.h"

class Cliente;

class ListaClientes
{
private:

	Lista<Cliente>* customers;

public:

	ListaClientes();
	~ListaClientes();
	//--------------------------------------------
	Lista<Cliente>* getLista();
	void agregarCliente(Cliente* nuevo);
	void eliminarCliente(string ID);
	void setMorosos();
	Cliente* getClienteEsp(string ID);
	//--------------------------------------------
	string toString();
	string Activos();
	string Inactivos();
	string Morosos();
	string sencilloClientes();
	//--------------------------------------------
	void enviaArchivoList(ostream& salida);
	static ListaClientes* recuperaArchivoList(istream& entrada);
	void guardarListaClientes();
	void leerListaClientes();
};
