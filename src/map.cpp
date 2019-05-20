#include "map.h"

void Map::addNode (int id, int x, int y, Tipo tipo) {
	Node novo = Node(x, y, id, tipo);
	this->pontos.push_back(novo);

	Tipo tip = NONE;
	if (tipo != tip) {
		this->interece.push_back(novo);
	}
}

void Map::addEstrada (int id, int nodeIdInicio, int nodeIdDestino) {
	Node inicio;
	Node destino;

	for (unsigned int i = 0; i != this->pontos.size(); i++) {

		if (this->pontos[i].getId() == nodeIdInicio)
			inicio = this->pontos[i];

		if (this->pontos[i].getId() == nodeIdDestino)
			destino = this->pontos[i];

	}

	Estrada nova = Estrada(id, inicio, destino);
	this->estradas.push_back(nova);
}








