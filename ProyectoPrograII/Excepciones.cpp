#include "Excepciones.h"

void IntOutRange(int minR, int maxR, int var, bool cont) {
	if (var > maxR || var < minR) {
		throw(invalid_argument("Fuera de rango!!!"));
	}
	cont = true;
}

void letter_w_int(int g, bool cont) {
	if (cin.fail()) {
		throw(invalid_argument("Tipo incorrecto!!!"));
	}
	cont = true;
}

void notFoundList() {
	throw(invalid_argument)("Elemento no presente en la lista!!!");
}