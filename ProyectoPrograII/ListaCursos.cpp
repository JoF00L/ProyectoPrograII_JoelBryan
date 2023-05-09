#include "ListaCursos.h"

ListaCursos::ListaCursos() { subjects = new Lista<Curso>; }

ListaCursos::~ListaCursos() { delete subjects; }

//-----------------------------------------------------------------------------------------------------

Lista<Curso>* ListaCursos::getLista() { return subjects; }

void ListaCursos::agregarCurso(Curso* nuevo) { 	subjects->agregar(nuevo); }

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

//-----------------------------------------------------------------------------------------------------

string ListaCursos::toString() {
	stringstream s;
	s << *subjects << endl;
	return s.str();
}

string ListaCursos::cursoBasicos() {
	stringstream s;
	s << "Listado de cursos: \n" << endl;
	for (int i = 0; i < subjects->getSize(); i++) {
		s << "-> " << subjects->getNodoEsp(i)->getDato()->getCodigo() << " - " << subjects->getNodoEsp(i)->getDato()->getNombre() << endl;
	}
	return s.str();
}

void ListaCursos::guardarListaGrupos(){
	ofstream salida;
	Nodo<Curso>* actual = subjects->getNodoEsp(0);

	salida.open("../ListaCursos.txt");
	while (actual != NULL)
	{
		if (salida.good()) {
			actual->getDato()->guardarCurso(salida);
		}
		actual = actual->getSig();
	}
	salida.close();
}

void ListaCursos::leerListaCursos(){
	ifstream entrada;
	Curso* curs;
	entrada.open("../ListaCursos.txt");

	if (entrada.good()) {
		while (!entrada.eof()) {
			curs = Curso::leerCurso(entrada);
			if (curs != nullptr) {
				subjects->agregar(curs);
			}
		}
	}
	entrada.close();
}
