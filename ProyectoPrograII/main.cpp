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
;	Cliente* test = new Cliente("test1", "", fechaActual, 'a', bm);
;	Cliente* test2 = new Cliente("test2", "", fechaActual, 'b', bm);
;	Cliente* test3 = new Cliente("test3", "", fechaActual, 'c', bm);

	Lista<Cliente>* l1 = new Lista<Cliente>;
	l1->agregar(test);
	l1->agregar(test2);
	l1->agregar(test3);

	cout << l1->toString() << endl;
	cin.get();
	system("cls");
	l1->eliminarPos(3); //probando el eliminar basico
	cout << l1->toString() << endl;

	delete fechaActual, test, bm, l1;

    return 0;
}
