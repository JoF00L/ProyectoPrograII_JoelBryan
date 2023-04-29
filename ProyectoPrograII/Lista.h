#pragma once
#include "Nodo.h"

/// Clase de tipo plantilla por lo que no
/// necesita de un cpp

template <typename T>
class Lista {
private:
	Nodo<T>* primero;
	
public:
	Lista();
	~Lista();
	//--------------------------------------------
	bool vacia();
	void agregar(T*);
	bool eliminar(string);
	//--------------------------------------------
	string toString();
};

//------------------------------------------------------------------------------------------------------

template <typename T>
Lista<T>::Lista(){ primero = NULL; }

template <typename T>
bool Lista<T>::vacia(){ return (primero == NULL); }

//------------------------------------------------------------------------------------------------------

template <typename T>
void Lista<T>::agregar(T* nuevo){
	if(vacia){
		primero = new Nodo<T>(nuevo, nullptr);
	}
	else{
		Nodo<T>* actual = primero;
		while(actual->getSig())
			actual = actual->getSig();
		actual->setSig(new Nodo<T>(nuevo, nullptr));
	}
}

template <typename T>

bool Lista<T>::eliminar(string id) //Creo que es mejor buscar a la persona en relacion a la cedula
{
	return false; //Terminar
}

template <typename T>
string Lista<T>::toString(){
	stringstream s;
	if (vacia())
		s << "La lista esta vacia! " << endl;
	else{
		Nodo<T>* actual = primero;
		while(actual != nullptr){
			s << actual->nodoString();
		}
	}
	return s.str();
}

template <typename T>
Lista<T>::~Lista() {
	Nodo<T>* actual = primero;
	while(primero != nullptr){
		actual = primero->getSig();
		primero = nullptr;
		delete primero;
		primero = actual;
	}
	actual = nullptr;
	delete actual;
}