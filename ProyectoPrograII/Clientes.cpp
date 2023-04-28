#include "Clientes.h"

Cliente::Cliente()
{
	nombre = " ";
	cedula = " ";
	fecha_nacimiento = new Fecha;
	sexo = '-';
	bio = new Biometricos;
}

Cliente::Cliente(string nom, string id, Fecha* nacimiento, char sex, Biometricos* bioData)
{
	nombre = nom;
	cedula = id;
	fecha_nacimiento = nacimiento;
	sexo = sex;
	bio = bioData;
}

Cliente::~Cliente() { delete fecha_nacimiento, bio; }

//-----------------------------------------------------------------------------------------------------

void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setCedula(string id) { cedula = id; }
void Cliente::setFechaNacimiento(Fecha* nacimiento) { fecha_nacimiento = nacimiento; }
void Cliente::setSexo(char sex) { sexo = sex; }
void Cliente::setPeso(float weight) { bio->setPeso(weight); }
void Cliente::setAltura(float height) { bio->setAltura(height); }
void Cliente::setMasaMuscular(float mm) { bio->setMasaMuscular(mm); }
void Cliente::setGrasaCorporal(float gc) { bio->setGrasaCorporal(gc); }

//------------------------------------------------------------------------------------------------------

string Cliente::getNombre() { return nombre; }
string Cliente::getCedula() { return cedula; }
Fecha* Cliente::getFechaNacimiento() { return fecha_nacimiento; }
char Cliente::getSexo() { return sexo; }
float Cliente::getPeso() { return bio->getPeso(); }
float Cliente::getAltura() { return bio->getAltura(); }
float Cliente::getMasaMuscular() { return bio->getMasaMuscular(); }
float Cliente::getGrasaCorporal() { return bio->getGrasaCorporal(); }

//------------------------------------------------------------------------------------------------------

string Cliente::toString() {
	stringstream s;
	s << "Datos del cliente: " << endl;
	s << "============================" << endl;
	s << "- Nombre: " << nombre << endl;
	s << "- C" << char(130) << "dula: " << cedula << endl;
	s << "- Sexo: " << sexo << endl;
	s << "- Fecha de nacimiento: " << fecha_nacimiento << endl;
	s << bio->toString(); //sobrecargar operador en clase para quitar toString() y dejar solo s << bio;
	s << "============================\n" << endl;
	return s.str();
}

//------------------------------------------------------------------------------------------------------

// HACER SOBRECARGA DE OPERADOR
