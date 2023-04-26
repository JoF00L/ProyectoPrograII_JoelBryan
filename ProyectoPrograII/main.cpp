#include "Fecha.h"
#include <iostream>  
using namespace std;

int main()
{
	Fecha* fechaActual = new Fecha;

	cout << fechaActual->toString() << endl;

	delete fechaActual;

    return 0;
}
