#pragma once
#include <iostream>
using namespace std;

/// Clase de tipo plantilla por lo que no
/// necesita de un cpp

template <typename T>
class Nodo
{
private:

	T* dato;
	Nodo<T>* sig;

public:

	Nodo();
	Nodo(T*, Nodo<T>*);
	~Nodo();
	//--------------------------------------------
	void setSig(Nodo<T>*);
	void setDato(T*);
	//--------------------------------------------
	T* getDato();
	Nodo<T>* getSig();
	//--------------------------------------------
	string nodoString();

};

template <typename T>
Nodo<T>::Nodo(T* info, Nodo<T>* sig)
{
	this->dato = info;
	sig = NULL;
}

template <typename T>
Nodo<T>::~Nodo() { }

//-------------------------------------------------------------------------

template <typename T>
void Nodo<T>::setSig(Nodo<T>* next) { sig = next };

template <typename T>
void Nodo<T>::setDato(T* info) { datoi = info; }

//-------------------------------------------------------------------------

template <typename T>
T* Nodo<T>::getDato() { return dato; }

template <typename T>
Nodo<T>* Nodo<T>::getSig() { return sig; }

//-------------------------------------------------------------------------

template <typename T>
string Nodo<T>::nodoString() {
	//Este creo que lo tenemos que ajustar con lo de la sobrecarga de operadores
	//para implementarlos no solo hacer lo de stringstream s << dato.toString()
	//sino que s << dato (por la sobrecarga)
}