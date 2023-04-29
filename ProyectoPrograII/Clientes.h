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
    Cliente(string nom, string id, Fecha* fecha_nacimiento, char sex, Biometricos* bioData);
    ~Cliente();
    //--------------------------------------------
    void setSexo(char sex);
    void setNombre(string nom);
    void setCedula(string id);
    void setPeso(float p);
    void setAltura(float a);
    void setMasaMuscular(float mm);
    void setGrasaCorporal(float gc);
    void setFechaNacimiento(Fecha* fecha_nacimiento);
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
    string toString() const;

};

ostream& operator<<(ostream& output, const Cliente& a);