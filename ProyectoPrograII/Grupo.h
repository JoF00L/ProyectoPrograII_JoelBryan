#pragma once
#include "ListaClientes.h"
#include <sstream>

class ListaClientes; //por cualquier cosa si no es necesario lo pueden borrar despues

class Grupo{
private:
	
	char dia;
	int numGrupo;
	string nomInstructor;
	string idInstructor;
	ListaClientes* alumnos; //cantidad de matriculados = getSize() de alumnos

public:

	Grupo();
	Grupo(char day, int num, string instruct, string idIns);
	~Grupo();
	//-------------------------------
	void setNumGrupo(int num);
	void setDia(char d);
	void setNomInst(string nom);
	void setIdInst(string id);
	//-------------------------------
	int getnumGrupo();
	char getDia();
	string getNomInst();
	string getIdInst();
	//-------------------------------
	string toString() const;

};

ostream& operator<<(ostream& output, const Grupo& g);

