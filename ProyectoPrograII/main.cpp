#include "Gimnasio.h"
#include <iostream> 
#include <windows.h>
using namespace std;

int main()
{
	system("color 03");

	Gimnasio* g = new Gimnasio;

	g->menu();

	delete g;

	return 0;
}
