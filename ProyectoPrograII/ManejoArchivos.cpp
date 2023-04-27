#include "ManejoArchivos.h"
ManejoArchivos::ManejoArchivos() {
	//tal vez le podemos agregar un atributo privado fstream
}

string ManejoArchivos::Logo() {
	string str;
	stringstream s;
	ifstream out("logo_triatlon.txt", ios::in);
	
	if(!out){
		//Podriamos agregar una excepcion aca o siempre que se habran archivos
	}
	else {
		while (!out.eof()) {
			getline(out, str);
			s << str << endl;
		}

		out.close();
	}

	return s.str();
}