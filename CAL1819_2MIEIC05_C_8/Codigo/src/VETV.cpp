#include "VETV.h"

VETV::VETV(Tipo tipo, Node* pontoInicial) {
	this->tipo = tipo;
	this->pontoInicial = pontoInicial;
}

void VETV::setTipo(Tipo tipo) {
	this->tipo = tipo;
}

Tipo VETV::getTipo() {
	return this->tipo;
}

void VETV::setPontoInicial(Node* node) {
	this->pontoInicial = node;
}

Node* VETV::getPontoInicail() {
	return this->pontoInicial;
}

void VETV::setCaminho(std::vector<Node*> nodes) {
	this->caminho = nodes;
}

std::vector<Node*> VETV::getCaminho() {
	return this->caminho;
}


