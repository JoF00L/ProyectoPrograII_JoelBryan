#include "Pago.h"

Pago::Pago(int costo) {
	fechaPago = new Fecha;
	mes = fechaPago->getMes();
	monto = costo;
}

Pago::Pago(Fecha* fechaNueva, int nuevoMes, int costo){
	fechaPago = fechaNueva;
	mes = nuevoMes;
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
	int wMes;
	switch (mes){
	case 1: case 4:case 5: case 6: case 7: case 3: wMes = 16; break;
	case 2: case 8: case 10: wMes = 17; break;
	case 9: case 11: wMes = 19; break;
	case 12: wMes = 18; break; 
	}

	s << setw(10) << *fechaPago << setw(wMes) << convierteMes(mes)  << setw(wMes+4) << monto << endl;
	return s.str();
}

void Pago::guardarPago(ostream& salida){
	fechaPago->guardarFecha(salida);
	salida << mes << '\t';
	salida << monto << '\n';
}

Pago* Pago::leerPago(istream& entrada){
	Fecha* fech;
	string m = "", mo = "";
	fech = Fecha::leerFecha(entrada);
	getline(entrada, m, '\t');
	getline(entrada, mo, '\n');
	int _m = convertirInt(m);
	int _mo = convertirInt(mo);
	return new Pago(fech, _m, _mo);
}

ostream& operator<<(ostream& output, const Pago& data) {
	output << data.toString();
	return output;
}