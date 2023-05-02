#include "ListaCursos.h"

ListaCursos::ListaCursos() { subjects = new Lista<Curso>; }

ListaCursos::~ListaCursos() { delete subjects; }

//-------------------------------------------------------------------------

void ListaCursos::agregarCurso(Curso* nuevo) { subjects->agregar(nuevo); }

void ListaCursos::eliminarCurso(string code) {
	int borrar = 0;
	if (subjects->getNodoEsp(0)->getDato()->getCodigo() == code) {
		subjects->eliminarPos(0);
		return;
	}
	while (subjects->getNodoEsp(borrar)->getDato()->getCodigo() != code) {
		borrar++;
	}
	subjects->eliminarPos(borrar);
}

Curso* ListaCursos::getCursoEsp(string code) {
	int buscar = 0;
	if (subjects->getNodoEsp(0)->getDato()->getCodigo() == code) {
		return subjects->getNodoEsp(0)->getDato();
	}
	while (subjects->getNodoEsp(buscar)->getDato()->getCodigo() != code) {
		buscar++;
	}
	return subjects->getNodoEsp(buscar)->getDato();
}

//-------------------------------------------------------------------------

string ListaCursos::toString() {
	stringstream s;
	s << *subjects << endl;
	return s.str();
}

string ListaCursos::porNivel(int lvl) {
	stringstream s;
	for (int i = 0; i < subjects->getSize(); i++) {
		if (subjects->getNodoEsp(i) != NULL && subjects->getNodoEsp(i)->getDato()->getNivel() == lvl) {
			s << *subjects->getNodoEsp(i) << endl;
		}
	}
	return s.str();
}