#include "Pago.h"

Pago::Pago(int costo) {
	fechaPago = new Fecha;
	mes = fechaPago->getMes();
	monto = costo;
}

Pago::~Pago() { delete fechaPago; }

void Pago::setMes(int nuevoMes){
	mes = nuevoMes;
}

void Pago::setMonto(int costo){
	monto = costo;
}

Fecha* Pago::getFechaPago(){
	return fechaPago;
}

int Pago::getMes(){
	return mes;
}

int Pago::getMonto(){
	return monto;
}

string Pago::convierteMes(int Mes) const {
	stringstream s;
	switch (Mes) {
	case 1: s << "Enero"; break;
	case 2: s << "Febrero"; break;
	case 3: s << "Marzo"; break;
	case 4: s << "Abril"; break;
	case 5: s << "Mayo"; break;
	case 6: s << "Junio"; break;
	case 7: s << "Julio"; break;
	case 8: s << "Agosto"; break;
	case 9: s << "Septiembre"; break;
	case 10: s << "Octubre"; break;
	case 11: s << "Noviembre"; break;
	case 12: s << "Diciembre"; break;
	}
	return s.str();
}

string Pago::toString() const{
	stringstream s;
	s << "Fecha de pago   Mes cancelado   Monto cancelado";
	s << *fechaPago << "   " << mes << "   " << monto;
	return s.str();
}

ostream& operator<<(ostream& output, const Pago& data) {
	output << data.toString();
	return output;
}