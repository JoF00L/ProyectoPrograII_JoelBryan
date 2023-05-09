#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/// Clase para el control de archivos general
///	-> Guardar datos
/// -> Cargar datos
/// -> Modificacion de datos


class ManejoArchivos
{
public:
	ManejoArchivos();
	string Logo();
};

int convertirInt(string s);
float convertirFloat(string s);
double convertirFloat(string s);
char convertirChar(string s);
bool convertirBool(string s);
