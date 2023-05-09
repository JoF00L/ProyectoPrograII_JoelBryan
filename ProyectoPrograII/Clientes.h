#pragma once
#include "Fecha.h"
#include "ListaCursos.h"
#include "ListaPagos.h"
#include "Biometricos.h"
#define MAX_CURSOS 4

class Curso;
class ListaCursos;

class Cliente
{
private:
    
    string nombre;
    string cedula;
    string telefono;
    Fecha* fecha_nacimiento;
    char sexo;
    int estado;
    //Expediente
    Biometricos* bio;
    ListaCursos* cursos;
    ListaPagos* pagos;

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
    void setEstado(int est);
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
    int getEstado();
    Fecha* getFechaNacimiento();
    ListaCursos* getListaCursos();
    ListaPagos* getListaPagos();
    //--------------------------------------------
	void agregarCurso(Curso* cur);
    string toString() const;
    string gruposMatriculados() const;
    //--------------------------------------------
};

ostream& operator<<(ostream& output, const Cliente& client);