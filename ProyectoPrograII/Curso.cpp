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

string Curso::toString(){
    stringstream s;
    s << "Descripcion del curso: " << descripcion << endl;
    s << "Nivel: " << tipoNivel() << endl;
    s << "Cupo Maximo: " << cupoMax << endl;
    return s.str();
}
