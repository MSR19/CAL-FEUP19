#ifndef MAP_H_
#define MAP_H_

#include <string>
#include "Estrada.h"
#include "node.h"
#include "graphviewer.h"


class Map {
private:
	GraphViewer graphviewer;
	std::vector<Node> pontos;
	std::vector<Node> interece;
	std::vector<Estrada> estradas;
	std::vector<Node> solucao;

	void addNode (int id, int x, int y, Tipo tipo);
	void addEstrada (int id, int nodeIdInicio, int nodeIdDestino);
public:
	Map (string cidade);
	void solution ();
	void dijkstra (Node init, Node dest);
};


#endif
