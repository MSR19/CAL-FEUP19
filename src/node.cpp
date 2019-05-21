#include "node.h"

Node::Node(float x, float y, int id, Tipo tipo) {
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

float Node::getX() {
	return this->x;
}

float Node::getY() {
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


