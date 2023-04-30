#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Clientes.h"
#include "Lista.h"
#include <iostream>  
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

	delete fechaActual, test, bm, l1;

    return 0;
}
