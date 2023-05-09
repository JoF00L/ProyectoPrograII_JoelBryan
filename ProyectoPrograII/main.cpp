#include "Gimnasio.h"
#include <iostream> 
using namespace std;

int main()
{
	Gimnasio* g = new Gimnasio;

	g->menu();

	delete g;
	//Pago* p = new Pago(25000);
	//ListaPagos* pl = new ListaPagos;
	//pl->nuevoPago(p);

	//cout << pl->retornaMesCancelado() << endl;

	return 0;
}
