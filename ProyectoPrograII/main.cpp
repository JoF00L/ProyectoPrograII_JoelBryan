#include "Fecha.h"
#include "ManejoArchivos.h"
#include "Clientes.h"
#include "ListaClientes.h"
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
	cout << *l1->getClienteEsp("TuLa") << endl;
	cin.get();
	system("cls");
	l1->eliminarCliente("TuLa"); //probando el eliminar posicion (test2) y el basico porque son los dos metodos juntos
	cout << *l1->getLista() << endl;

	delete fechaActual, test, test2, test3, bm, l1;

    return 0;
}
