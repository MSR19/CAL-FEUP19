#include "Estrada.h"


Estrada::Estrada(int id, Node* ini, Node *dest) {
	this->id = id;
	this->ini =ini;
	this->dest = dest;
	int x = dest->getX() - ini->getX();
	int y = dest->getY() - ini->getY();
	this->peso = sqrt((x*x) + (y*y));
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










