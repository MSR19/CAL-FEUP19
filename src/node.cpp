#include "node.h"

Node::Node(std::string nome,Tipo tipo, std::vector<Estrada> estradas) {
	this->nome = nome;
	this->tipo = tipo;
	this->estradas = estradas;
	this->visited = false;
}

Node::Node(std::string nome, Tipo tipo) {
	this->nome = nome;
	this->tipo = tipo;
	this->visited = false;
}

std::vector<Estrada> Node::getEstradas() {
	return this->estradas;
}

std::string Node::getNome() {
	return this->nome;
}

Tipo Node::getTipo() {
	return this->tipo;
}

bool Node::isVisited() {
	return this->visited;
}

void Node::setVisited() {
	this->visited = true;
}


