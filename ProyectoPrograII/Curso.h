#pragma once
#include "ListaClientes.h"
#include "ListaGrupos.h"
#include <sstream>

class Grupo;
class ListaGrupos; //NO BORRAR ESTO

class Curso{
private:

	int nivel;
	int cupoMax;
	int cantGrupo;
	string nombre;
	string codigo; 
	string descripcion; 
	ListaGrupos* grupitos;

public:

	Curso();
	Curso(string nom, string code, string info, int lvl, int amount, int cant);//falta fechas y reeservas
	~Curso();
	//--------------------------------------------
	void setNombre(string nom);
	void setCodigo(string code);
	void setDescripcion(string info);
	void setCantGrupo(int cant);
	void setNivel(int lvl);
	void setCupo(int amount);
	void nuevoGrupo(Grupo* add);
	int getCantGrupo();
	//--------------------------------------------
	string getNombre();
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