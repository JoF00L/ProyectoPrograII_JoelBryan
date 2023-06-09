#include "ListaGrupos.h"

ListaGrupos::ListaGrupos() { groups = new Lista<Grupo>; }

ListaGrupos::~ListaGrupos() { delete groups; }

//-----------------------------------------------------------------------------------------------------

Lista<Grupo>* ListaGrupos::getLista() { return groups; }

//-----------------------------------------------------------------------------------------------------

void ListaGrupos::nuevoGrupo(Grupo* nuevo) { groups->agregar(nuevo); }


void ListaGrupos::eliminarGrupo(int num) { 
	int borrar = 0;
	if (groups->getNodoEsp(0)->getDato()->getnumGrupo() == num) {
		groups->eliminarPos(0);
		return;
	}
	while (groups->getNodoEsp(borrar)->getDato()->getnumGrupo() != num) {
		borrar++;
	}
	groups->eliminarPos(borrar);
} //Hay que ver que atributo usamos para identificar los grupos

Grupo* ListaGrupos::getGrupoEsp(int num)
{
	int buscar = 0;
	if (groups->getNodoEsp(0)->getDato()->getnumGrupo() == num) {
		return groups->getNodoEsp(0)->getDato();
	}
	while (groups->getNodoEsp(buscar)->getDato()->getnumGrupo() != num) {
		buscar++;
	}
	return groups->getNodoEsp(buscar)->getDato();
}

//-----------------------------------------------------------------------------------------------------

string ListaGrupos::toString(){
	stringstream s;
	s << *groups << endl;
	return s.str();
}

void ListaGrupos::guardarListaGrupos(ostream& salida) {
	Nodo<Grupo>* actual = groups->getNodoEsp(0);

	while (actual != NULL) {
		if (salida.good()) {
			actual->getDato()->guardarGrupo(salida);
		}
		actual = actual->getSig();
	}
}

ListaGrupos* ListaGrupos::leerListaGrupos(istream& entrada) {
	Grupo* dat = NULL;
	ListaGrupos* lista = new ListaGrupos;
	if (entrada.good()) {
		while (!entrada.eof()) {
			dat = Grupo::leerGrupo(entrada);
			if (dat != NULL) {
				lista->getLista()->agregar(dat);
			}
		}
	}
	return lista;
}