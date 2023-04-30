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

	Nodo(T*);
	~Nodo();
	//--------------------------------------------
	void setSig(Nodo<T>*);
	void setDato(T*);
	//--------------------------------------------
	T* getDato();
	Nodo<T>* getSig();
	//--------------------------------------------
	string toString() const;

};

template <typename T>
Nodo<T>::Nodo(T* info) {
	this->dato = info;
	sig = NULL;
}

template <typename T>
Nodo<T>::~Nodo() { }

//-------------------------------------------------------------------------

template <typename T>
void Nodo<T>::setSig(Nodo<T>* next) { sig = next; }

template <typename T>
void Nodo<T>::setDato(T* info) { dato = info; }

//-------------------------------------------------------------------------

template <typename T>
T* Nodo<T>::getDato() { return dato; }

template <typename T>
Nodo<T>* Nodo<T>::getSig() { return sig; }

//-------------------------------------------------------------------------

template <typename T>
string Nodo<T>::toString() const{
	stringstream s;
	s << *dato;
	return s.str();
}

template <typename T>
ostream& operator<<(ostream& output, const Nodo<T>& n) {
	output << n.toString();
	return output;
}