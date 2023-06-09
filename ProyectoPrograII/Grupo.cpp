#include "Grupo.h"

Grupo::Grupo() { 
	dia = 'z';
	numGrupo = -1;
	cupoMaximo = 0;
	horario = "NULL";
	nomInstructor = "NULL";
	idInstructor = "NULL";
	alumnos = new ListaClientes;
	inicio = new Fecha;
}

Grupo::Grupo(char day, int num, int cupo, string instruct, string idIns, Fecha* fInicio) {
	dia = day;
	numGrupo = num;
	cupoMaximo = cupo;
	horario = "NULL";
	nomInstructor = instruct;
	idInstructor = idIns;
	alumnos = new ListaClientes;
	inicio = fInicio;
}

Grupo::~Grupo() { }

//-----------------------------------------------------------------------------------------------------

void Grupo::setNumGrupo(int num) { numGrupo = num; }
void Grupo::setCupoMaximo(int cupo) { cupoMaximo = cupo; }
void Grupo::setDia(char d) { dia = d; }
void Grupo::setNomInst(string nom) { nomInstructor = nom; }
void Grupo::setIdInst(string id) { idInstructor = id; }
void Grupo::setInicio(Fecha* fInicio) { inicio = fInicio; }
void Grupo::recibeHorario(string h) { horario = h; }
void Grupo::setLista(ListaClientes* li) { alumnos = li; }
void Grupo::setHorario(int horaC, int minC, int horaF, int minF) {
	stringstream s;
	if (horaC < 10) {
		s << "0";
	}
	s << horaC << ":";
	if (minC < 10) {
		s << "0";
	}
	s << minC << " a ";
	
	if (horaF < 10) {
		s << "0";
	}
	s << horaF << ":";
	if (minF < 10) {
		s << "0";
	}
	s << minF;
	horario = s.str();
}


//-----------------------------------------------------------------------------------------------------

int Grupo::getnumGrupo() { return numGrupo; }
int Grupo::getCupoMaximo() { return cupoMaximo; }
char Grupo::getDia() { return dia; }
string Grupo::getNomInst() { return nomInstructor; }
string Grupo::getIdInst() { return idInstructor; }
string Grupo::getHorario() { return horario; }
Fecha* Grupo::getInicio(){ return inicio; }
ListaClientes* Grupo::getLista() { return alumnos; }

//-----------------------------------------------------------------------------------------------------

char Grupo::diaMayuscula(char d) const{
	char c = ' ';
	switch(d){
	case 'l': c = 'L'; break;
	case 'k': c = 'K'; break;
	case 'm': c = 'M'; break;
	case 'j': c = 'J'; break;
	case 'v': c = 'V'; break;
	case 's': c = 'S'; break;
	case 'd': c = 'D'; break;
	}
	return c;
}

string Grupo::toString() const{
	stringstream s;
	s << "Nombre del instructor: " << nomInstructor << endl;
	s << "Id del instructor: " << idInstructor << endl;
	s << "Cupo m" << char(162) << "ximo: " << cupoMaximo << endl;
	s << "Cantidad de matriculados: " << alumnos->getLista()->getSize() << endl;
	s << "Dia del curso: " << dia << endl;
	s << "Horario: " << horario << endl;
	return s.str();
}

string Grupo::sencillo() {
	stringstream s;
	s << "     " << this->numGrupo;
	s << "\t\t " << this->cupoMaximo;
	s << "\t      " << alumnos->getLista()->getSize();
	return s.str();
}

string Grupo::sencillo2() {
	stringstream s;
	s << "   " << this->numGrupo << "\t  " << this->dia << "\t" << horario << "\t " << this->cupoMaximo << "\t   ";
	s << alumnos->getLista()->getSize();
	return s.str();
}

void Grupo::agregarCliente(Cliente* c) {
	if ((alumnos->getLista()->getSize() < cupoMaximo) && (c->getEstado() == 1)) {
		alumnos->agregarCliente(c);
	}
}

void Grupo::guardarGrupo(ostream& salida) {
	salida << dia << '\t';
	salida << numGrupo << '\t';
	salida << cupoMaximo << '\t';
	salida << horario << '\t';
	salida << nomInstructor << '\t';
	salida << idInstructor << '\n';
	alumnos->enviaArchivoList(salida);
	inicio->guardarFecha(salida);
}

Grupo* Grupo::leerGrupo(istream& entrada) {
	Fecha* fech = new Fecha;
	ListaClientes* lista = new ListaClientes;
	string d = "", num = "", cupo = "", hor = "", nomi = "", idi = "";
	getline(entrada, d, '\t');
	getline(entrada, num, '\t');
	getline(entrada, cupo, '\t');
	getline(entrada, hor, '\t');
	getline(entrada, nomi, '\t');
	getline(entrada, idi, '\n');
	char _d = convertirChar(d);
	int _num = convertirInt(num);
	int _cupo = convertirInt(cupo);
	fech = Fecha::leerFecha(entrada);
	Grupo* grup = new Grupo(_d, _num, _cupo, nomi, idi, fech);
	lista = ListaClientes::recuperaArchivoList(entrada);
	grup->setLista(lista);
	grup->recibeHorario(hor);
	return grup;
}

ostream& operator<<(ostream& output, const Grupo& g) {
	output << g.toString() << endl;
	return output;
}