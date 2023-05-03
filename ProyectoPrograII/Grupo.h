#pragma once
#include "ListaClientes.h"
#include <sstream>

class ListaClientes; //por cualquier cosa si no es necesario lo pueden borrar despues

class Grupo{
private:
	
	int numGrupo;
	//agregar el atributo lista de clientes

public:

	Grupo();
	Grupo(int num);
	~Grupo();
	//-------------------------------
	void setNumGrupo(int num);
	//-------------------------------
	int getnumGrupo();
	//-------------------------------
	string toString() const;

};

ostream& operator<<(ostream& output, const Grupo& g);