#include "Fecha.h"
#include "ManejoArchivos.h"
#include <iostream>  
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;
	ManejoArchivos* files = new ManejoArchivos;

	cout << fechaActual->toString() << endl;
	cout << files->Logo() << endl;


	delete fechaActual, files;

    return 0;
}
