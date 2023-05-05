#pragma once
#include "Fecha.h"
#include "Curso.h"
#include "ListaCursos.h"
#include "Biometricos.h"
#define MAX_CURSOS 4

class Cliente
{
private:
    
    string nombre;
    string cedula;
    string telefono;
    Fecha* fecha_nacimiento;
    char sexo;
    string estado;
    //Expediente
    Biometricos* bio;
    //Creo que le agregamos la lista de cursos despues

public:
    
    Cliente();
    Cliente(string nom, string id, string phone, Fecha* fecha_nacimiento, char sex, Biometricos* bioData);
    ~Cliente();
    //--------------------------------------------
    void setSexo(char sex);
    void setNombre(string nom);
    void setCedula(string id);
    void setTelefono(string phone);
    void setPeso(float p);
    void setAltura(float a);
    void setMasaMuscular(float mm);
    void setGrasaCorporal(float gc);
    void setEstado(string active);
    void setFechaNacimiento(Fecha* fecha_nacimiento);
    //--------------------------------------------
    char getSexo();
    string getNombre();
    string getCedula();
    string getTelefono();
    float getPeso();
    float getAltura();
    float getMasaMuscular();
    float getGrasaCorporal(); 
    string getEstado();
    Fecha* getFechaNacimiento();
    //--------------------------------------------
    string toString() const;
    //--------------------------------------------
    // void matricular(Curso* c) -> metodo que agrega un curso de la lista principal de cursos
    // pero para que pueda matricular tiene que verificar que el expediente de pagos este actualizado
};

ostream& operator<<(ostream& output, const Cliente& client);