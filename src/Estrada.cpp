#include "Estrada.h"


Estrada::Estrada(std::string nome, Node* ini, Node *dest, double peso) {
	this->nome = nome;
	this->ini =ini;
	this->dest = dest;
	this->peso = peso;
}

std::string Estrada::getNome() {
	return this->nome;
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










