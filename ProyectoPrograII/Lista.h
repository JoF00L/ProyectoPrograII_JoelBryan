#pragma once
#include "Nodo.h"

/// Clase de tipo plantilla por lo que no usamos .cpp

template <typename T>
class Lista {
private:
	Nodo<T>* primero;
	
public:

	Lista();
	~Lista();
	//--------------------------------------------
	bool esVacia();
	void agregar(T* dato);
	void eliminar(); //Elimina primer elemento de la lista | para el destructor o pruebas 
	void eliminarEspecifico(string id); //Para uso especifico
	//--------------------------------------------
	string toString();

};

//------------------------------------------------------------------------------------------------------

template <typename T>
Lista<T>::Lista() { primero = NULL; }

template <typename T>
bool Lista<T>::esVacia(){ return primero == NULL; }

//------------------------------------------------------------------------------------------------------

template <typename T>
void Lista<T>::agregar(T* dato){
	Nodo<T>* nuevo = new Nodo<T>(dato);
	Nodo<T>* temp = primero;

	if (esVacia())
	{
		primero = nuevo;
	}
	else
	{
		while (temp->getSig())
		{
			temp = temp->getSig();
		}
		temp->setSig(nuevo);
	}
}

//------------------------------------------------------------------------------------------------------

template <typename T>
void Lista<T>::eliminar() 
{
	//No estoy seguro de porque no funciona :/
	Nodo<T>* actual = primero;
	primero = primero->getSig();
	delete actual;
}

template <typename T>
void Lista<T>::eliminarEspecifico(string id) {
	




}
//------------------------------------------------------------------------------------------------------

template <typename T> 
string Lista<T>::toString(){
	stringstream s;
	Nodo<T>* temp = primero;
	if (esVacia()) {
		//s << "Lista vacia" << endl; //Agregar una excpecion aca despues
	}
	while (temp) {
		//s << *temp;
		temp = temp->getSig();
	}
	return s.str();
}

template <typename T>
Lista<T>::~Lista() {
	while (!esVacia()) {
		eliminar();
	}
}

//------------------------------------ ITERADOR DE LA LISTA ------------------------------------------