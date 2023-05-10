#include "Excepciones.h"
#include "ListaClientes.h"

void IntOutRange(int minR, int maxR, int var, bool cont) {
	if (var > maxR || var < minR) {
		throw invalid_argument("Fuera de rango!!!");
	}
	cont = false;
}

void intNegative(int n) {
	if (n < 0) {
		throw invalid_argument("No se pueden ingresar valores negativos!!!");
	}
}

//void letter_w_int(int g, bool cont) {
//	if (!cin) {
//		throw invalid_argument("Solo se pueden ingresar numeros!!!");
//	}
//	else if (cin.good()) {
//		cont = false;
//	}
//}
