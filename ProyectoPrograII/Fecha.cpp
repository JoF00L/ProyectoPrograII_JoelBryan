#include "Fecha.h"

Fecha::Fecha() {
	for (int i = 0; i < max; i++) {
		fecha[i] = 0;
	}
}

Fecha::Fecha(int d, int m, int a) {
	fecha[0] = d;
	fecha[1] = m;
	fecha[2] = a;
}

string Fecha::diferenciaFechas(Fecha* f) {
	stringstream s;
	s << "Dias: " << abs((f->fecha[0] - fecha[0])) << endl;
	s << "Meses: " << abs((f->fecha[1] - fecha[1])) << endl;
	s << "Annos: " << abs(devuelveEdad(f)) << endl;
	return s.str();
}

bool Fecha::esMenor(Fecha* f) {
	if (f->fecha[1] > fecha[1])
		return true;
	else if (f->fecha[1] == fecha[1] && f->fecha[0] <= fecha[0])
		return true;
	return false;
}

int Fecha::devuelveEdad(Fecha* f) {
	int edad = 0;
	if (f->fecha[2] < fecha[2]) {
		edad = (fecha[2] - f->fecha[2]);
		if (esMenor(f))
			edad--;
	}
	return edad;
}

string Fecha::toString() {
	stringstream s;

	if (fecha[0] < 10)
		s << "0";
	s << fecha[0] << " / ";
	if (fecha[1] < 10)
		s << "0";
	s << fecha[1] << " / ";
	s << fecha[2] << endl;

	return s.str();
}

Fecha::~Fecha() { }
