#pragma once
#include "ListaClientes.h"
#include <sstream>

class ListaClientes; //por cualquier cosa si no es necesario lo pueden borrar despues

class Grupo{
private:
	
	char dia;
	int numGrupo;
	int cupoMaximo;
	string horario;
	string nomInstructor;
	string idInstructor;
	ListaClientes* alumnos; //cantidad de matriculados = getSize() de alumnos

public:

	Grupo();
	Grupo(char day, int num, int cupo, string instruct, string idIns);
	~Grupo();
	//-------------------------------
	void setNumGrupo(int num);
	void setDia(char d);
	void setNomInst(string nom);
	void setIdInst(string id);
	void setCupoMaximo(int cupo);
	//-------------------------------
	int getnumGrupo();
	int getCupoMaximo();
	char getDia();
	string getNomInst();
	string getIdInst();
	ListaClientes* getLista();
	//-------------------------------
	string toString() const;
	string sencillo();

};

ostream& operator<<(ostream& output, const Grupo& g);

