#include "Grupo.h"

Grupo::Grupo() { 
	numGrupo = -1; 
}

Grupo::Grupo(int num) {
	numGrupo = num;
}

Grupo::~Grupo() { }

//-----------------------------------------------------------------------------------------------------

void Grupo::setNumGrupo(int num) { numGrupo = num; }

//-----------------------------------------------------------------------------------------------------

int Grupo::getnumGrupo() { return numGrupo; }

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