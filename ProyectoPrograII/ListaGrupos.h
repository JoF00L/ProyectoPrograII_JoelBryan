#pragma once
#include "Grupo.h"
#include "Lista.h"

class Grupo;

class ListaGrupos
{
private:
	
	Lista<Grupo>* groups;

public:

	ListaGrupos();
	~ListaGrupos();
	//--------------------------------------------
	Lista<Grupo>* getLista();
	void nuevoGrupo(Grupo* nuevo);
	void eliminarGrupo(int num);
	Grupo* getGrupoEsp(int num);
	//--------------------------------------------
	string toString();

};

