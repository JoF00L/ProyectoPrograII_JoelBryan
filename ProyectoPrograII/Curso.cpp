#include "Curso.h"

Curso::Curso(){
    codigo = "NULL";
    descripcion = "Sin descripcion";
    nivel = 1;
    cupoMax = 30;
    alumnos = new ListaClientes;
}

Curso::Curso(string code, string info, int lvl, int amount) {
    codigo = code;
    descripcion = info;
    nivel = lvl;
    cupoMax = amount;
    alumnos = new ListaClientes;
}

Curso::~Curso() { delete alumnos; }
//-------------------------------------------------------------------------

void Curso::setCodigo(string code) { codigo = code; }
void Curso::setDescripcion(string info) { descripcion = info; }
void Curso::setNivel(int lvl) {
    if (lvl < 1 || lvl > 3) {
        //hacer excepcion
    }
    nivel = lvl;
}
void Curso::setCupo(int amount) { cupoMax = amount; }
void Curso::agregarAlumno(Cliente* add) { alumnos->agregarCliente(add); }

//-------------------------------------------------------------------------

string Curso::getCodigo() { return codigo; };
string Curso::getDescripcion() { return descripcion; }
int Curso::getNivel() { return nivel; }
int Curso::getCupo() { return cupoMax; }
ListaClientes* Curso::getAlumnos() { return alumnos; }

//-------------------------------------------------------------------------

string Curso::tipoNivel(int n) const{
    string tn;
    switch (n) {
    case 1: tn = "Principiante"; break;
    case 2: tn = "Intermedio"; break;
    case 3: tn = "Avanzado"; break;
    }
    return tn;
}

/*string Curso::horario(Fecha* inicio, Fecha* fin, int d1, int d2) { //si los trabajamos con 2 dias (ejemplo)
    stringstream s;
    s << "Fecha de inicio: " << inicio->toString() << endl;
    s << "Fecha de fin: " << fin->toString() << endl;
    s << "Dias: ";
    return s.str();
}*/

//-------------------------------------------------------------------------

string Curso::toString() const{
    stringstream s;
    s << "Descripcion del curso: " << descripcion << endl;
    s << "Nivel: " << tipoNivel(nivel) << endl;
    s << "Cupo Maximo: " << cupoMax << endl;
    // Fechas del curso
    return s.str();
}

ostream& operator<<(ostream& output, const Curso& info) {
    output << info.toString();
    return output;
}