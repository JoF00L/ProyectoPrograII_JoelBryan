#pragma once
#include "ListaClientes.h"
#include "ListaGrupos.h"
#include <sstream>

class Grupo;
class ListaGrupos; 

class Curso{
private:

	int nivel;
	int cantGrupo;
	string nombre;
	string codigo; 
	string descripcion; 
	ListaGrupos* grupitos;

public:

	Curso();
	Curso(string nom, string code, string info, int lvl, int cant);
	~Curso();
	//--------------------------------------------
	void setNombre(string nom);
	void setCodigo(string code);
	void setDescripcion(string info);
	void setCantGrupo(int cant);
	void setNivel(int lvl);
	void setLista(ListaGrupos* g);
	void nuevoGrupo(Grupo* add);
	int getCantGrupo();
	//--------------------------------------------
	string getNombre();
	string getCodigo();
	string getDescripcion();
	int getNivel();
	ListaGrupos* getGrupos();
	//--------------------------------------------
	string tipoNivel(int lvl) const;
	string toString() const;
	string detalleGrupos();
	string masDetalleGrupos();
	//--------------------------------------------
	void guardarCurso(ostream& salida);
	static Curso* leerCurso(istream& entrada);
};

ostream& operator<<(ostream& output, const Curso& subject);