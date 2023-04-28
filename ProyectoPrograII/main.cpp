#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Clientes.h"
#include <iostream>  
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;
	ManejoArchivos* files = new ManejoArchivos;
	
	cout << fechaActual->toString() << endl;
	cout << files->Logo() << endl;

	system("cls");
	Biometricos* bm = new Biometricos;
	Cliente* test = new Cliente("test1", "", fechaActual, 't', bm);

	cout << test->toString() << endl;

	delete fechaActual, files, bm, test;

    return 0;
}
