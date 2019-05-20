#include "node.h"

Node::Node(int x, int y, std::string nome, Tipo tipo) {
	this->x = x;
	this->y = y;
	this->id = id;
	this->tipo = tipo;
	this->visited = false;
}

std::vector<Estrada> Node::getEstradas() {
	return this->estradas;
}

void Node::addEstrada (Estrada estrada) {
	this->estradas.push_back(estrada);
}

int Node::getId() {
	return this->id;
}

int Node::getX() {
	return this->x;
}

int Node::getY() {
	return this->y;
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


