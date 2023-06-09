#include "Clientes.h"

Cliente::Cliente()
{
	nombre = " NULL";
	cedula = "NULL";
	telefono = "NULL";
	fecha_nacimiento = new Fecha;
	sexo = '-';
	estado = 1;
	bio = new Biometricos;
	cursos = new ListaCursos();
	pagos = new ListaPagos();
}

Cliente::Cliente(string nom, string id, string phone, Fecha* nacimiento, char sex, Biometricos* bioData)
{
	nombre = nom;
	cedula = id;
	telefono = phone;
	fecha_nacimiento = nacimiento;
	estado = 1;
	sexo = sex;
	bio = bioData;
	cursos = new ListaCursos();
	pagos = new ListaPagos();
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
void Cliente::setEstado(int est) { estado = est; }
void Cliente::setListaCursos(ListaCursos* li) { cursos = li; }
void Cliente::setListaPagos(ListaPagos* lp) { pagos = lp; }

//------------------------------------------------------------------------------------------------------

string Cliente::getNombre() { return nombre; }
string Cliente::getCedula() { return cedula; }
string Cliente::getTelefono() { return telefono; }
Fecha* Cliente::getFechaNacimiento() { return fecha_nacimiento; }
char Cliente::getSexo() { return sexo; }
int Cliente::getEstado() { return estado; }
float Cliente::getPeso() { return bio->getPeso(); }
float Cliente::getAltura() { return bio->getAltura(); }
float Cliente::getMasaMuscular() { return bio->getMasaMuscular(); }
float Cliente::getGrasaCorporal() { return bio->getGrasaCorporal(); }
ListaCursos* Cliente::getListaCursos() { return cursos; }
ListaPagos* Cliente::getListaPagos() { return pagos; }
//------------------------------------------------------------------------------------------------------

void Cliente::agregarCurso(Curso* cur){
	//excepcion

	if(cursos->getLista()->getSize() <= MAX_CURSOS) { 
		cursos->agregarCurso(cur);
	}
}

string Cliente::toString() const{
	stringstream s;
	s << "\t  Datos del cliente: " << endl;
	s << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;
	
	s << "- Nombre: " << nombre << endl;
	s << "- C" << char(130) << "dula: " << cedula << endl;
	s << "- Sexo: " << sexo << endl;
	s << "- Estado: ";
	switch (estado)	{
	case 1:
		s << "Activo" << endl;
		break;
	case 2:
		s << "Inactivo" << endl;
		break;
	case 3:
		s << "Moroso" << endl;
		break;
 	}
	s << "- Tel" << char(130) << "fono: " << telefono << endl;
	s << "- Fecha de nacimiento: " << *fecha_nacimiento << endl;
	s << *bio << endl; 
	
	if (!cursos->getLista()->esVacia()) {
		s << endl << gruposMatriculados() << endl;
	}

	return s.str();
}


string Cliente::gruposMatriculados() const{
	stringstream s;
	s << "\t  Grupos matriculados:" << endl;
	s << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;
	for (int i = 0; i < cursos->getLista()->getSize(); i++) {
		s << "- [" << cursos->getLista()->getNodoEsp(i)->getDato()->getCodigo() << "] ";
		s << cursos->getLista()->getNodoEsp(i)->getDato()->getNombre() << ", grupo #";
		s << cursos->getLista()->getNodoEsp(i)->getDato()->getGrupos()->getLista()->getNodoEsp(i)->getDato()->getnumGrupo() << endl;
	}
	return s.str();
}

//------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& output, const Cliente& c) {
	output << c.toString() << endl;
	return output;
}

void Cliente::guardarCliente(ostream& salida) {
	salida << nombre << '\t';
	salida << cedula << '\t';
	salida << telefono << '\t';
	salida << sexo << '\t';
	salida << estado << '\n';
	fecha_nacimiento->guardarFecha(salida);
	bio->guardarBio(salida);
	cursos->enviaArchivoList(salida);
	pagos->guardarListaPagos(salida);
}

Cliente* Cliente::leerCliente(istream& entrada) {
	ListaCursos* lista = new ListaCursos;
	ListaPagos* listPagos = new ListaPagos;
	Fecha* fech = new Fecha;
	Biometricos* biom = new Biometricos;
	string name = "", ced = "", tel = "", sex = "", est = "";
	getline(entrada, name, '\t');
	getline(entrada, ced, '\t');
	getline(entrada, tel, '\t');
	getline(entrada, sex, '\t');
	getline(entrada, est, '\n'); 
	char _sex = convertirChar(sex); 
	int _est = convertirInt(est);
	fech = Fecha::leerFecha(entrada);
	biom = Biometricos::leerBio(entrada);
	Cliente* clie = new Cliente(name, ced, tel, fech, _sex, biom);
	listPagos = ListaPagos::leerListaPagos(entrada);
	lista = ListaCursos::recuperaArchivoList(entrada);
	clie->setEstado(_est);
	clie->setListaPagos(listPagos);
	clie->setListaCursos(lista);
	return clie;
}
