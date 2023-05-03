#pragma once
#include "Lista.h"
#include "Fecha.h"
class Gimnasio{
public:
	Gimnasio();
	~Gimnasio();
	void menu();
	void adminGeneral();
	void controlDeportistas();
	void controlCursos();
	void controlGrupos();
	void controlPagos();
	void guardarArchSalir();
	void nombreGim();
	void montoMensualidad();
	void ingresoDeportista();
	void modifDeportista();
	void listadoDeportistas();
	void detalleDeportista();
};

