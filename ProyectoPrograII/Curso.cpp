#include "Curso.h"

Curso::Curso(){
    codigo = "NULL";
    descripcion = "Sin descripcion";
    nivel = 1;
    cupoMax = 30;
    grupitos = new ListaGrupos;
}

Curso::Curso(string code, string info, int lvl, int amount) {
    codigo = code;
    descripcion = info;
    nivel = lvl;
    cupoMax = amount;
    grupitos = new ListaGrupos;
}

Curso::~Curso() { delete grupitos; }

//-----------------------------------------------------------------------------------------------------

void Curso::setCodigo(string code) { codigo = code; }
void Curso::setDescripcion(string info) { descripcion = info; }
void Curso::setNivel(int lvl) {
    if (lvl < 1 || lvl > 3) {
        //hacer excepcion
    }
    nivel = lvl;
}
void Curso::setCupo(int amount) { cupoMax = amount; }

void Curso::nuevoGrupo(Grupo* add) { grupitos->nuevoGrupo(add); }

//-----------------------------------------------------------------------------------------------------

string Curso::getCodigo() { return codigo; };
string Curso::getDescripcion() { return descripcion; }
int Curso::getNivel() { return nivel; }
int Curso::getCupo() { return cupoMax; }
ListaGrupos* Curso::getGrupos() { return grupitos; }

//-----------------------------------------------------------------------------------------------------

string Curso::tipoNivel(int n) const{
    stringstream tn;
    switch (n) {
    case 1: tn << "Principiante"; break;
    case 2: tn << "Intermedio"; break;
    case 3: tn << "Avanzado"; break;
    }
    return tn.str();
}

/*string Curso::horario(Fecha* inicio, Fecha* fin, int d1, int d2) { //si los trabajamos con 2 dias (ejemplo)
    stringstream s;
    s << "Fecha de inicio: " << inicio->toString() << endl;
    s << "Fecha de fin: " << fin->toString() << endl;
    s << "Dias: ";
    return s.str();
}*/

//-----------------------------------------------------------------------------------------------------

string Curso::toString() const{
    stringstream s;
    s << "-=-=-=- INFO DEL CURSO -=-=-=-\n" << endl;
    s << "Codigo del curso: " << codigo << endl;
    s << "Descripcion del curso: " << descripcion << endl;
    s << "Nivel: " << tipoNivel(nivel) << endl;
    s << "Cupo Maximo: " << cupoMax << endl;
    s << "\n-=-=-=-=-=- GRUPOS -=-=-=-=-=-\n" << endl;
    s << *grupitos->getLista();
    return s.str();
}

ostream& operator<<(ostream& output, const Curso& info) {
    output << info.toString() << endl;
    return output;
}