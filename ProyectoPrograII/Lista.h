#pragma once
#include "Nodo.h"
#include "Excepciones.h"

template <typename T>
class Lista {
private:

	Nodo<T>* primero;
	int size;

public:

	Lista();
	~Lista();
	//--------------------------------------------
	int getSize();
	bool esVacia() const;
	void agregar(T* dato);
	void eliminarInicio();  
	void eliminarPos(int pos);
	Nodo<T>* getNodoEsp(int pos);
	//--------------------------------------------
	string toString() const;
    //--------------------------------------------
};

//------------------------------------------------------------------------------------------------------

template <typename T>
Lista<T>::Lista() : primero(NULL), size(0) { }

template <typename T>
Lista<T>::~Lista() {
	while (!esVacia()) {
		eliminarInicio();
	}
}
//------------------------------------------------------------------------------------------------------
template<typename T>
int Lista<T>::getSize() { return size; }

template <typename T>
bool Lista<T>::esVacia() const { return primero == NULL; }

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
		throw invalid_argument("Posicion invalida!!!");
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
	if (pos > size || pos < 0 || pos == size) {
		throw invalid_argument("Posicion invalida!!!");
	}
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
string Lista<T>::toString() const{
	stringstream s;
	Nodo<T>* temp = primero;
	if (esVacia()) {
		return "Vacia"; //Agregar una excpecion aca despues
	}
	while (temp) {
		s << *temp;
		temp = temp->getSig();
	}
	return s.str();
}

//------------------------------------------------------------------------------------------------------

template <typename T>
ostream& operator<<(ostream& output, const Lista<T>& list) {
	output << list.toString();
	return output;
}

//------------------------------------------------------------------------------------------------------
