#include "Curso.h"

Curso::Curso(){
    nombre = "Sin nombre";
    codigo = "NULL";
    descripcion = "Sin descripcion";
    nivel = 1;
    cupoMax = 30;
	cantGrupo = 0;
    grupitos = new ListaGrupos;
}

Curso::Curso(string nom, string code, string info, int lvl, int amount, int cant) {
    nombre = nom;
    codigo = code;
    descripcion = info;
    nivel = lvl;
    cupoMax = amount;
    cantGrupo = cant;
    grupitos = new ListaGrupos;
}

Curso::~Curso() { delete grupitos; }

//-----------------------------------------------------------------------------------------------------

void Curso::setNombre(string nom){
    nombre = nom;
}

void Curso::setCodigo(string code) { codigo = code; }
void Curso::setDescripcion(string info) { descripcion = info; }
void Curso::setNivel(int lvl) {
    if (lvl < 1 || lvl > 3) {
        //hacer excepcion
    }
    nivel = lvl;
}
void Curso::setCupo(int amount) { cupoMax = amount; }

void Curso::nuevoGrupo(Grupo* add) { 
    //EXCEPCION
    if (grupitos->getLista()->getSize() < cantGrupo) {
        grupitos->nuevoGrupo(add);
    }
}

void Curso::setCantGrupo(int cant) { cantGrupo = cant; }

//-----------------------------------------------------------------------------------------------------

string Curso::getNombre(){ return nombre;}
string Curso::getCodigo() { return codigo; };
string Curso::getDescripcion() { return descripcion; }
int Curso::getNivel() { return nivel; }
int Curso::getCupo() { return cupoMax; }
int Curso::getCantGrupo() { return cantGrupo;  }
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

//-----------------------------------------------------------------------------------------------------

string Curso::toString() const{
    stringstream s;
    s << "-=-=-=-=-= INFO DEL CURSO =-=-=-=-=-\n" << endl;
    s << "- Nombre del curso: " << nombre << endl;
    s << "- Codigo del curso: " << codigo << endl;
    s << "- Descripcion del curso: " << descripcion << endl;
    s << "- Nivel: " << tipoNivel(nivel) << endl;
    s << "- Cupo Maximo: " << cupoMax << endl;
    s << "\n-=-=-=-=-=-=-= GRUPOS =-=-=-=-=-=-=-\n" << endl;
    s << *grupitos->getLista();
    return s.str();
}

// #Grupo = # Grupo; Cupo = cupoMax; 

ostream& operator<<(ostream& output, const Curso& info) {
    output << info.toString() << endl;
    return output;
}