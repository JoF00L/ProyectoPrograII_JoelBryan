#include "Gimnasio.h"
#include <iostream> 
using namespace std;

int main()
{
	Gimnasio* g = new Gimnasio;

	g->menu();

	delete g;

    return 0;
}
