#include "Expediente.h"

Expediente::Expediente(){
	bool activo = false;
}

Expediente::Expediente(bool a){
	activo = a;
}

Expediente::~Expediente() {
}

string Expediente::toString(){
	stringstream s;
	s << "Activo: " << activo << endl;
	return s.str();
}

