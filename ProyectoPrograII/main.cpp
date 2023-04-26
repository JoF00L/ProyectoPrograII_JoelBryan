#include "Fecha.h"
#include <iostream>  
#pragma warning(disable:4996)
using namespace std;

int main()
{
	time_t t = time(nullptr);
	struct tm* now = localtime(&t);

	int Year = now->tm_year + 1900;
	int Month = now->tm_mon + 1;
	int Day = now->tm_mday;
	
	Fecha* fechaActual = new Fecha(Day, Month, Year);

	cout << fechaActual->toString() << endl;

	delete fechaActual;

    return 0;
}
