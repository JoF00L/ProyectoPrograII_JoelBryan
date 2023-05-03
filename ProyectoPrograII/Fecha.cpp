#include "Fecha.h"

Fecha::Fecha() {
	time_t tempo = time(nullptr);
	struct tm* fechaActual = localtime(&tempo);

	fecha[0] = fechaActual->tm_mday;
	fecha[1] = fechaActual->tm_mon + 1;
	fecha[2] = fechaActual->tm_year + 1900;
}

Fecha::Fecha(int d, int m, int a) {
	fecha[0] = d;
	fecha[1] = m;
	fecha[2] = a;
}

Fecha::~Fecha() { }

//-----------------------------------------------------------------------------------------------------

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

//-----------------------------------------------------------------------------------------------------

string Fecha::diferenciaFechas(Fecha* f) {
	stringstream s;
	s << "Dias: " << abs((f->fecha[0] - fecha[0])) << endl;
	s << "Meses: " << abs((f->fecha[1] - fecha[1])) << endl;
	s << "A" << char(164) << "os: " << abs(devuelveEdad(f)) << endl;
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

//-----------------------------------------------------------------------------------------------------

string Fecha::toString() {
	stringstream s;

	if (fecha[0] < 10) {
		s << "0";
	}
	s << fecha[0] << " / ";
	if (fecha[1] < 10) {
		s << "0";
	}
	s << fecha[1] << " / ";
	s << fecha[2];

	return s.str();
}


Fecha* Fecha::getFechaActual() {
	time_t t;

	struct tm actualT;
	time(&t);

	localtime_s(&actualT, &t);

	return new Fecha(actualT.tm_mday, actualT.tm_mon + 1, actualT.tm_year + 1900);


}

string Fecha::normalizarMes() {

	switch (mes) {
	case 1: return "Enero"; break;
	case 2: return "Febrero"; break;
	case 3: return "Marzo"; break;
	case 4: return "Abril"; break;
	case 5: return "Mayo"; break;
	case 6: return "Junio"; break;
	case 7: return "Julio"; break;
	case 8: return "Agosto"; break;
	case 9: return "Septiembre"; break;
	case 10: return "Octubre"; break;
	case 11: return "Noviembre"; break;
	case 12: return "Diciembre"; break;

	default:
		break;
	}
}