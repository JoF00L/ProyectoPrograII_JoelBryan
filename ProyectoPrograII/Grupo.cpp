#include "Grupo.h"

Grupo::Grupo() { 
	dia = 'n';
	numGrupo = -1;
	nomInstructor = "NULL";
	idInstructor = "NULL";
	alumnos = new ListaClientes;
}

Grupo::Grupo(char day, int num, string instruct, string idIns) {
	dia = day;
	numGrupo = num;
	nomInstructor = instruct;
	idInstructor = idIns;
	alumnos = new ListaClientes;
}

Grupo::~Grupo() { }

//-----------------------------------------------------------------------------------------------------

void Grupo::setNumGrupo(int num) { numGrupo = num; }
void Grupo::setDia(char d) { dia = d; }
void Grupo::setNomInst(string nom) { nomInstructor = nom; }
void Grupo::setIdInst(string id) { idInstructor = id; }

//-----------------------------------------------------------------------------------------------------

int Grupo::getnumGrupo() { return numGrupo; }
char Grupo::getDia() { return dia; }
string Grupo::getNomInst() { return nomInstructor; }
string Grupo::getIdInst() { return idInstructor; }

//-----------------------------------------------------------------------------------------------------

string Grupo::toString() const{
	stringstream s;
	s << "HOLA SOY EL GRUPO #" << numGrupo;
	return s.str();
}

ostream& operator<<(ostream& output, const Grupo& g) {
	output << g.toString() << endl;
	return output;
}