#pragma once
#include "ListaClientes.h"
#include "ListaGrupos.h"
#include <sstream>

class Grupo;
class ListaGrupos; //NO BORRAR ESTO

class Curso{
private:
	
	string codigo; 
	string descripcion; 
	int nivel;
	int cupoMax;
	ListaGrupos* grupitos;

public:

	Curso();
	Curso(string code, string info, int lvl, int amount);//falta fechas y reeservas
	~Curso();
	//--------------------------------------------
	void setCodigo(string code);
	void setDescripcion(string info);
	void setNivel(int lvl);
	void setCupo(int amount);
	void nuevoGrupo(Grupo* add);
	//--------------------------------------------
	string getCodigo();
	string getDescripcion();
	int getNivel();
	int getCupo();
	ListaGrupos* getGrupos();
	//--------------------------------------------
	string tipoNivel(int lvl) const;
	string toString() const;

};

ostream& operator<<(ostream& output, const Curso& subject);