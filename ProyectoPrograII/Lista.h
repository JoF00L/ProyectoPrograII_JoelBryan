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
	bool vacia();
	void agregar(T*);
	bool eliminar(int);
	string toString();
	~Lista();
};

template <typename T>
Lista<T>::Lista(){
	primero = nullptr;
}

template <typename T>
bool Lista<T>::vacia(){
	return (primero == nullptr);
}

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
bool Lista<T>::eliminar(int n){
	return false;
}

template <typename T>
string Lista<T>::toString(){
	stringstream s;
	if(vacia())
	return .str();
}