#include "Clientes.h"

Cliente::Cliente()
{
	nombre = " NULL";
	cedula = "NULL";
	telefono = "NULL";
	fecha_nacimiento = new Fecha;
	sexo = '-';
	estado = true;
	bio = new Biometricos;
}

Cliente::Cliente(string nom, string id, string phone, Fecha* nacimiento, char sex, Biometricos* bioData)
{
	nombre = nom;
	cedula = id;
	telefono = phone;
	fecha_nacimiento = nacimiento;
	estado = true;
	sexo = sex;
	bio = bioData;
}

Cliente::~Cliente() { delete fecha_nacimiento, bio; }

//-----------------------------------------------------------------------------------------------------

void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setCedula(string id) { cedula = id; }
void Cliente::setTelefono(string phone) { telefono = phone; }
void Cliente::setFechaNacimiento(Fecha* nacimiento) { fecha_nacimiento = nacimiento; }
void Cliente::setSexo(char sex) { sexo = sex; }
void Cliente::setPeso(float p) { bio->setPeso(p); }
void Cliente::setAltura(float a) { bio->setAltura(a); }
void Cliente::setMasaMuscular(float mm) { bio->setMasaMuscular(mm); }
void Cliente::setGrasaCorporal(float gc) { bio->setGrasaCorporal(gc); }
void Cliente::setEstado(bool active) { estado = active; }

//------------------------------------------------------------------------------------------------------

string Cliente::getNombre() { return nombre; }
string Cliente::getCedula() { return cedula; }
string Cliente::getTelefono() { return telefono; }
Fecha* Cliente::getFechaNacimiento() { return fecha_nacimiento; }
char Cliente::getSexo() { return sexo; }
bool Cliente::getEstado() { return estado; }
float Cliente::getPeso() { return bio->getPeso(); }
float Cliente::getAltura() { return bio->getAltura(); }
float Cliente::getMasaMuscular() { return bio->getMasaMuscular(); }
float Cliente::getGrasaCorporal() { return bio->getGrasaCorporal(); }

//------------------------------------------------------------------------------------------------------

string Cliente::toString() const{
	stringstream s;
	s << "\t  Datos del cliente: " << endl;
	s << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;
	
	s << "- Nombre: " << nombre << endl;
	s << "- C" << char(130) << "dula: " << cedula << endl;
	s << "- Sexo: " << sexo << endl;
	s << "- Estado: ";
	switch (estado)	{
	case true:
		s << "activo" << endl;
	case false:
		s << "inactivo" << endl;
 	}
	s << "- Tel" << char(130) << "fono: " << telefono << endl;
	s << "- Fecha de nacimiento: " << *fecha_nacimiento << endl;
	s << *bio << endl; //Ya hice la sobrecarga
	
	s << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	return s.str();
}

//------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& output, const Cliente& c) {
	output << c.toString() << endl;
	return output;
}