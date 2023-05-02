#include "Curso.h"

Curso::Curso(){
    descripcion = "Sin descripcion";
    nivel = 1;
    cupoMax = 30;
}

Curso::Curso(string d, int n, int c) {
    descripcion = d;
    nivel = n;
    cupoMax = c;
}

Curso::~Curso(){
}

string Curso::tipoNivel(int n){
    string tn;
    switch (n) {
    case 1: tn = "Principiante"; break;
    case 2: tn = "Intermedio"; break;
    case 3: tn = "Avanzado"; break;
    }
    return tn;
}

/*string Curso::horario(Fecha* inicio, Fecha* fin, int d1, int d2) {//si los trabajamos con 2 dias (ejemplo)
    stringstream s;
    s << "Fecha de inicio: " << inicio->toString() << endl;
    s << "Fecha de fin: " << fin->toString() << endl;
    s<<"Dias"
    return s.str();
}*/

string Curso::toString(){
    stringstream s;
    s << "Descripcion del curso: " << descripcion << endl;
    s << "Nivel: " << tipoNivel(nivel) << endl;
    s << "Cupo Maximo: " << cupoMax << endl << endl;
    return s.str();
}
