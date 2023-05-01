#include "Horario.h"

Horario::Horario(Fecha* i, Fecha* f){
	inicio = i;
	fin = f;
    cantidad = 0;
    for (int i = 0; i < maxDias; i++) {
        dias[i] = 0;
    }
    hora[0] = 0;
    hora[1] = 0;
}

Horario::~Horario(){
    delete inicio;
    delete fin;
}

string Horario::convierteDia(int d) {
    string dia;
    switch (d) {
    case 1: dia = "Lunes"; break;
    case 2: dia = "Martes"; break;
    case 3: dia = "Miercoles"; break;
    case 4: dia = "Jueves"; break;
    case 5: dia = "Viernes"; break;
    case 6: dia = "Sabado"; break;
    case 7: dia = "Domingo"; break;
    }
    return dia;
}

void Horario::agregaDias(int d){
    dias[cantidad] = d;
    cantidad++;
}

void Horario::agregaHoras(int h, int m){
    hora[0] = h;//horas
    hora[1] = m;//minutos
}

string Horario::toString(){
    stringstream s;
    s << "Horario: " << endl;
    s << "Fecha de inicio: " << inicio->toString() << endl;
    s << "Fecha de fin: " << fin->toString() << endl;
    s << "Dias: " << endl;
    for (int i = 0; i < cantidad; i++)
        s << "- " << convierteDia(dias[i]) << endl;
    s << "Hora: " << hora[0] << " : " << hora[1] << endl;
    return s.str();
}
