#include "Biometricos.h"

Biometricos::Biometricos() {
	peso = 0;
	altura = 0;
	masa_muscular = 0;
	grasa_corporal = 0;
}

Biometricos::Biometricos(float p, float a, float mm, float gc) {
	peso = p;
	altura = a;
	masa_muscular = mm;
	grasa_corporal = gc;
}

//-------------------------------------------------------------------------

void Biometricos::setPeso(float p) { peso = p; }
void Biometricos::setAltura(float a) { altura = a; }
void Biometricos::setMasaMuscular(float mm) { masa_muscular = mm; }
void Biometricos::setGrasaCorporal(float gc) { grasa_corporal = gc; }

//-------------------------------------------------------------------------

float Biometricos::getPeso() { return peso; }
float Biometricos::getAltura() { return altura; }
float Biometricos::getMasaMuscular() { return masa_muscular; }
float Biometricos::getGrasaCorporal() { return grasa_corporal; }

//-------------------------------------------------------------------------

string Biometricos::toString() {
	stringstream s;
	if (peso > 0) {
		s << "- Peso: " << peso << endl;
	}
	if (altura > 0) {
		s << "- Altura: " << altura << endl;
	}
	if (masa_muscular > 0) {
		s << "- Masa_muscular: " << masa_muscular << endl;
	}
	if (grasa_corporal > 0) {
		s << "- Grasa_corporal: " << grasa_corporal;
	}
	return s.str();
}

//-------------------------------------------------------------------------

//AGEGAR SOBRECARGAAA