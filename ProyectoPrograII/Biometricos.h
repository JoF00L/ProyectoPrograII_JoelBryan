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
	Biometricos(float p, float a, float mm, float gc);
	//--------------------------------------------
	virtual void setPeso(float weight);
	virtual void setAltura(float height);
	virtual void setMasaMuscular(float mm);
	virtual void setGrasaCorporal(float gc);
	//--------------------------------------------
	virtual float getPeso();
	virtual float getAltura();
	virtual float getMasaMuscular();
	virtual float getGrasaCorporal();
	//--------------------------------------------
	string toString();
};

//HACER SOBRECARGA OPERADOR << OFSTREAM