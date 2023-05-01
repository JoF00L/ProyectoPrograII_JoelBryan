#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Clientes.h"
#include "Lista.h"
#include <iostream> 
#include "Horario.h"
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;
	//ManejoArchivos* files = new ManejoArchivos;
	//
	//cout << fechaActual->toString() << endl;
	//cout << files->Logo() << endl;

	//system("cls");


	Biometricos* bm = new Biometricos(1.0, 1.0, 1.0, 1.0);
;	Cliente* test = new Cliente("test1", "", fechaActual, 't', bm);
	Nodo<Cliente>* n1 = new Nodo<Cliente>(test);

	Lista<Cliente>* l1 = new Lista<Cliente>;
	l1->agregar(test);

	cout << l1->toString() << endl;
	l1->eliminar(); //probando el eliminar basico
	cout << l1->toString() << endl;

	Fecha* x = new Fecha(10, 5, 2023);
	Horario* h = new Horario(fechaActual, x);
	h->agregaDias(1);
	h->agregaHoras(5, 30);
	cout << endl << h->toString() << endl;
	delete fechaActual, test, bm, l1, x, h;

    return 0;
}
