#pragma once
#include "ManejoArchivos.h"
#include "ListaCursos.h"
#include "ListaClientes.h"
#include "ListaGrupos.h"
#include "Fecha.h"
class Gimnasio{
private:
	
	string nombre;
	int montoMensual;
	Fecha* currentDate;
	ListaClientes* deportistas;
	ListaCursos* cursos;

public:

	Gimnasio();
	~Gimnasio();
	//-----------------------------
	void setNombre(string nom);
	void setMonto(int monto);
	//-----------------------------
	void menu();
	void adminGeneral();
	void controlDeportistas();
	void controlCursos();
	void controlGrupos();
	void controlPagos();
	void registroPago();
	void reportePagos();
	void guardarArchSalir();
	void nombreGim();
	void montoMensualidad();
	void ingresoDeportista();
	void modifDeportista();
	void listadoDeportistas();
	void detalleDeportista();
	void ingresoCurso();
	void reporteCurso();
	void modifCurso();
	void ingresoGrupo();
	void modifGrupo();
	void matriculaGrupo();
	void reporteGrupo();
	void reporteDepMat();
	void cancelacionMatricula();
	void guardarGimnasio();
	void leerGimnasio();
};

