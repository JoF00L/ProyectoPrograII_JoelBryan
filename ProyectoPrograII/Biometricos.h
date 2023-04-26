#pragma once
#include <sstream>
#include <iostream>
using namespace std;

/// DATOS BIOMETRICOS:
///		-> peso
///		-> altura
///		-> masaMuscular
///		-> grasaCorporal

class Biometricos
{
private:

	float peso;
	float altura;
	float masa_muscular;
	float grasa_corporal;
	
public:

	Biometricos();
	Biometricos(float, float, float, float);
	//--------------------------------------------
	virtual void setPeso(float);
	virtual void setAltura(float);
	virtual void setMasaMuscular(float);
	virtual void setGrasaCorporal(float);
	//--------------------------------------------
	virtual float getPeso();
	virtual float getAltura();
	virtual float getMasaMuscular();
	virtual float getGrasaCorporal();
	//--------------------------------------------
	string toString();
};

//HACER SOBRECARGA OPERADOR << OFSTREAM