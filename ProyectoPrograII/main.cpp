#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Curso.h"
#include "Clientes.h"
#include "Grupo.h"
#include "ListaClientes.h"
#include "ListaCursos.h"
#include "ListaGrupos.h"
#include <iostream> 
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;
	Biometricos* bm = new Biometricos(1.0, 1.0, 1.0, 1.0);
;	Cliente* test = new Cliente("test1", "tula", "11112222", fechaActual, 'a', bm);
;	Cliente* test2 = new Cliente("test2", "TuLa", "33334444", fechaActual, 'b', bm);
;	Cliente* test3 = new Cliente("test3", "tUlA", "55556666", fechaActual, 'c', bm);

	ListaClientes* l1 = new ListaClientes;
	l1->agregarCliente(test);
	l1->agregarCliente(test2);
	l1->agregarCliente(test3);

	cout << *l1->getLista() << endl;
	cin.get();
	system("cls");
	cout << *l1->getClienteEsp("TuLa") << endl; //mostrando el segundo
	cin.get();
	system("cls");
	l1->eliminarCliente("TuLa"); 
	cout << *l1->getLista() << endl; //elimando el segundo
	cin.get();
	system("cls");

	//-------------------------------------------------------------

	Grupo* grup1 = new Grupo(1);
	Grupo* grup2 = new Grupo(2);
	Grupo* grup3 = new Grupo(3);

	Curso* curs1 = new Curso("EIF203", "testing1", 1, 30);
	Curso* curs2 = new Curso("MAT200", "testing2", 2, 30);
	Curso* curs3 = new Curso("EIF200", "testing3", 3, 30);
	curs1->nuevoGrupo(grup1);
	curs2->nuevoGrupo(grup2);
	curs3->nuevoGrupo(grup3);

	ListaCursos* l2 = new ListaCursos;
	l2->agregarCurso(curs1);
	l2->agregarCurso(curs2);
	l2->agregarCurso(curs3);

	cout << *l2->getLista() << endl;
	cin.get();
	system("cls");
	cout << *l2->getCursoEsp("EIF200") << endl; //mostrando el ultimo
	cin.get();
	system("cls");
	l2->eliminarCurso("EIF200"); //Eliminando el ultimo
	cout << *l2->getLista() << endl;
	cin.get();
	system("cls");
	
	//-------------------------------------------------------------

	delete fechaActual, bm, l1, l2	;

    return 0;
}
