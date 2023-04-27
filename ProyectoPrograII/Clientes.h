#pragma once
#include "Fecha.h"
#include "Biometricos.h"

/// DATOS PERSONALES:
///		-> nombre
///		-> cedula
///		-> fecha nacimiento
///		-> sexo
/// EXPEDIENTE
/// LISTA DE CURSOS
///		-> Datos cada curso

class Cliente
{
private:
    
    string nombre;
    string cedula;
    Fecha* fecha_nacimiento;
    char sexo;
    Biometricos* bio;

public:
    
    Cliente();
    Cliente(string, string, Fecha*, char, Biometricos*);
    //--------------------------------------------
    void setSexo(char);
    void setNombre(string);
    void setCedula(string);
    void setPeso(float);
    void setAltura(float);
    void setMasaMuscular(float);
    void setGrasaCorporal(float);
    //--------------------------------------------
    char getSexo();
    string getNombre();
    string getCedula();
    float getPeso();
    float getAltura();
    float getMasaMuscular();
    float getGrasaCorporal(); 
    Fecha* getFechaNacimiento();
    //--------------------------------------------
    string toString();

};

// HACER SOBRECARGA OPERADOR << OFSTREAM