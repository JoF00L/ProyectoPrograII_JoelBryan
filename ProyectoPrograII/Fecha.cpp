#include "Fecha.h"

Fecha::Fecha() {
	time_t tempo = time(nullptr);
	struct tm* fechaActual = localtime(&tempo);

	dia = fechaActual->tm_mday;
	mes = fechaActual->tm_mon + 1;
	anio = fechaActual->tm_year + 1900;
}

Fecha::Fecha(int d, int m, int a) {
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha() { }

//-----------------------------------------------------------------------------------------------------

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

//-----------------------------------------------------------------------------------------------------

string Fecha::diferenciaFechas(Fecha* f) {
	stringstream s;
	s << "Dias: " << abs((f->getDia() - this->dia)) << endl;
	s << "Meses: " << abs((f->getMes() - this->mes)) << endl;
	s << "A" << char(164) << "os: " << abs(devuelveEdad(f)) << endl;
	return s.str();
}

bool Fecha::esMenor(Fecha* f) {
	if (f->getMes() > mes) {
		return true;
	}
	else if (f->getMes() == mes && f->getDia() <= dia) {
		return true;
	}
	return false;
}

int Fecha::devuelveEdad(Fecha* f) {
	int edad = 0;
	if (f->getAnio() < anio) {
		edad = (anio - f->getAnio());
		if (esMenor(f)) {
			edad--;
		}
	}
	return edad;
}

//-----------------------------------------------------------------------------------------------------

string Fecha::toString() const{
	stringstream s;

	if (dia < 10) {
		s << "0";
	}
	s << this->dia << " / ";
	if (mes < 10) {
		s << "0";
	}
	s << this->mes << " / ";
	s << this->anio;

	return s.str();
}

//-----------------------------------------------------------------------------------------------------

void Fecha::guardarFecha(ostream& salida) {
	salida << dia << '\t';
	salida << mes << '\t';
	salida << anio << '\n';
}

Fecha* Fecha::leerFecha(istream& entrada) {
	string _dia = "", _mes = "", _anio = "";
	getline(entrada, _dia, '\t');
	getline(entrada, _mes, '\t');
	getline(entrada, _anio, '\n');
	int valDia = convertirInt(_dia);
	int valMes = convertirInt(_mes);
	int valAnio = convertirInt(_anio);
	return new Fecha(valDia, valMes, valAnio);
}

ostream& operator<<(ostream& output, const Fecha& data) {
	output << data.toString();
	return output;
}