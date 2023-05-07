#include "Grupo.h"

Grupo::Grupo() { 
	dia = 'z';
	numGrupo = -1;
	cupoMaximo = 0;
	nomInstructor = "NULL";
	idInstructor = "NULL";
	alumnos = new ListaClientes;
}

Grupo::Grupo(char day, int num, int cupo, string instruct, string idIns) {
	dia = day;
	numGrupo = num;
	cupoMaximo = cupo;
	nomInstructor = instruct;
	idInstructor = idIns;
	alumnos = new ListaClientes;
}

Grupo::~Grupo() { }

//-----------------------------------------------------------------------------------------------------

void Grupo::setNumGrupo(int num) { numGrupo = num; }
void Grupo::setCupoMaximo(int cupo) { cupoMaximo = cupo; }
void Grupo::setDia(char d) { dia = d; }
void Grupo::setNomInst(string nom) { nomInstructor = nom; }
void Grupo::setIdInst(string id) { idInstructor = id; }

//-----------------------------------------------------------------------------------------------------

int Grupo::getnumGrupo() { return numGrupo; }
int Grupo::getCupoMaximo() { return cupoMaximo; }
char Grupo::getDia() { return dia; }
string Grupo::getNomInst() { return nomInstructor; }
string Grupo::getIdInst() { return idInstructor; }
ListaClientes* Grupo::getLista() { return alumnos; }

//-----------------------------------------------------------------------------------------------------

string Grupo::toString() const{
	stringstream s;
	s << "HOLA SOY EL GRUPO #" << numGrupo;
	return s.str();
}

string Grupo::sencillo() {
	return "";
}

ostream& operator<<(ostream& output, const Grupo& g) {
	output << g.toString() << endl;
	return output;
}