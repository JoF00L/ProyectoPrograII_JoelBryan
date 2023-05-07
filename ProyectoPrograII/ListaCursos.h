#pragma once
#include "Lista.h"
#include "Curso.h"

class Curso;

class ListaCursos
{
private:
	
	Lista<Curso>* subjects;
	
public:

	ListaCursos();
	~ListaCursos();
	//--------------------------------------------
	Lista<Curso>* getLista();
	void agregarCurso(Curso* nuevo);
	void eliminarCurso(string ID); 
	Curso* getCursoEsp(string ID);  
	//--------------------------------------------
	string toString(); //El toString general
	string cursoBasicos();
};

