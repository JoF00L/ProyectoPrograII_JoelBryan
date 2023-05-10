#include "Gimnasio.h"
#include <iostream> 
#include <windows.h>
using namespace std;
/*
	05/09/2023
	Programacion II - EIF204
	Joel Ramirez Vargas - 119020788
	Bryan Hernandez Hernandez - 402620925
	Proyecto #1
*/

int main()
{
	system("color 03");
	
	Gimnasio* g = new Gimnasio;
	g->leerGimnasio();
	g->menu();

	delete g; 
	
	return 0;
}
