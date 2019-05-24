#include "Estrada.h"


Estrada::Estrada(int id, Node* ini, Node *dest) {
	this->id = id;
	this->ini =ini;
	this->dest = dest;
	float x = dest->getX() - ini->getX();
	float y = dest->getY() - ini->getY();
	this->peso = sqrt((x*x) + (y*y));
	ini->addEstrada(*this);
	dest->addEstrada(*this);
}


Node* Estrada::getInicio() {
	return this->ini;
}

Node* Estrada::getDestino() {
	return this->dest;
}

double Estrada::getPeso() {
	return this->peso;
}










