#pragma once
#include "Fecha.h"
#include "ListaClientes.h"
#include <sstream>

class Cliente;
class ListaClientes; 

class Grupo{
private:
	
	char dia;
	int numGrupo;
	int cupoMaximo;
	string horario;
	string nomInstructor;
	string idInstructor;
	Fecha* inicio;
	ListaClientes* alumnos; 

public:

	Grupo();
	Grupo(char day, int num, int cupo, string instruct, string idIns, Fecha* fInicio);
	~Grupo();
	//-------------------------------
	void setNumGrupo(int num);
	void setDia(char d);
	void setNomInst(string nom);
	void setIdInst(string id);
	void setCupoMaximo(int cupo);
	void setInicio(Fecha* fInicio);
	void setHorario(int horaC, int minC, int horaF, int minF);
	//-------------------------------
	int getnumGrupo();
	int getCupoMaximo();
	char getDia();
	string getNomInst();
	string getIdInst();
	Fecha* getInicio();
	ListaClientes* getLista();
	//-------------------------------
	char diaMayuscula(char d) const;
	string toString() const;
	string sencillo();
	void agregarCliente(Cliente* student);
};

ostream& operator<<(ostream& output, const Grupo& g);

