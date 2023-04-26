#include "Fecha.h"

Fecha::Fecha() {
	time_t t = time(nullptr);
	struct tm* now = localtime(&t);

	fecha[0] = now->tm_mday;
	fecha[1] = now->tm_mon + 1;
	fecha[2] = now->tm_year + 1900;
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
