#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Clientes.h"
#include "Lista.h"
#include <iostream>  
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;
	ManejoArchivos* files = new ManejoArchivos;
	
	cout << fechaActual->toString() << endl;
	cout << files->Logo() << endl;

	system("cls");
	Biometricos* bm = new Biometricos(1.1, 1.2, 1.3, 1.4);
;	Cliente* test = new Cliente("test1", "", fechaActual, 't', bm);
	Nodo<Cliente>* n1 = new Nodo<Cliente>(test, NULL);

	cout << n1->nodoString() << endl;

	delete fechaActual, files, bm, n1;

    return 0;
}
