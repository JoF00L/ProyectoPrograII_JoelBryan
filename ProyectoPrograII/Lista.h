#pragma once
#include "Nodo.h"

/// Clase de tipo plantilla por lo que no usamos .cpp

template <typename T>
class Lista {
private:
	Nodo<T>* primero;
	int size;
public:

	Lista();
	~Lista();
	//--------------------------------------------
	bool esVacia();
	void agregar(T* dato);
	void eliminarInicio();  
	void eliminarUltimo();
	void eliminarPos(int pos);
	Nodo<T>* getNodoEsp(int pos);
	//--------------------------------------------
	string toString();

};

//------------------------------------------------------------------------------------------------------

template <typename T>
Lista<T>::Lista() : primero(NULL), size(0) { }

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
	size++;
}

//------------------------------------------------------------------------------------------------------

template <typename T>
void Lista<T>::eliminarInicio() 
{
	//No estoy seguro de porque no funciona :/
	Nodo<T>* actual = primero;
	primero = primero->getSig();
	delete actual;
	size--;
}

template <typename T>
void Lista<T>::eliminarPos(int pos) {
	Nodo<T>* actual = primero;
	Nodo<T>* borrar;

	if (pos > size || pos < 0 || pos == size) {
		return; //Hacer excepcion
	}
	if (pos == 0) {
		eliminarInicio();
		return;
	}
	for (int i = 0; i < pos - 1; i++) {
		if (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
	}
	borrar = actual->getSig();
	actual->setSig(borrar->getSig());
	delete borrar;
}

//------------------------------------------------------------------------------------------------------

template <typename T>
Nodo<T>* Lista<T>::getNodoEsp(int pos) {
	if (pos == 0) {
		return primero;
	}
	Nodo<T>* actual = primero;
	for (int i = 0; i < pos; i++) {
		if (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
	}
	return actual;
}

//------------------------------------------------------------------------------------------------------

template <typename T> 
string Lista<T>::toString(){
	stringstream s;
	Nodo<T>* temp = primero;
	if (esVacia()) {
		cout << "lista vacia" << endl; //Agregar una excpecion aca despues
	}
	while (temp) {
		s << *temp;
		temp = temp->getSig();
	}
	return s.str();
}

template <typename T>
Lista<T>::~Lista() {
	while (!esVacia()) {
		eliminarInicio();
	}
}
