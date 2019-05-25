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

void Node::setTipo(Tipo tipo) {
	this->tipo = tipo;
}

bool Node::isVisited() {
	return this->visited;
}

void Node::setVisited(bool visited) {
	this->visited = visited;
}

double Node::getPeso() {
	return this->peso;
}

void Node::setPeso(double peso) {
	this->peso = peso;
}

Node* Node::getCaminho() {
	return this->caminho;
}

void Node::setCaminho(Node* caminho) {
	this->caminho = caminho;
}
