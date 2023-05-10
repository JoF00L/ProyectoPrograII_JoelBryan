#include "Excepciones.h"

void IntOutRange(int minR, int maxR, int var, bool cont) {
	if (var > maxR || var < minR) {
		throw(invalid_argument("Fuera de rango!!!"));
	}
	cont = false;
}

void letter_w_int(int g, bool cont) {
	int s = 0;
	if (cin.fail()) {
		throw(invalid_argument("No es un INT!!!"));
	}
	cont = false;
}

void notFoundList() {
	throw(invalid_argument)("Elemento no presente en la lista!!!");
}