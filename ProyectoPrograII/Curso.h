#pragma once
#include "Lista.h"
#include "ListaClientes.h"
#include <sstream>

class Curso{
private:
	
	string codigo; // para identificarlos tipo EIF200 es funda
	string descripcion; // esto explicaria que es el curso
	int nivel;
	int cupoMax;
	ListaClientes* alumnos;

public:

	Curso();
	Curso(string code, string info, int lvl, int amount);//falta fechas y reeservas
	~Curso();
	//--------------------------------------------
	void setCodigo(string code);
	void setDescripcion(string info);
	void setNivel(int lvl);
	void setCupo(int amount);
	void agregarAlumno(Cliente* add);
	//--------------------------------------------
	string getCodigo();
	string getDescripcion();
	int getNivel();
	int getCupo();
	ListaClientes* getAlumnos();
	//--------------------------------------------
	string tipoNivel(int lvl) const;
	string toString() const;

};

ostream& operator<<(ostream& output, const Curso& data);