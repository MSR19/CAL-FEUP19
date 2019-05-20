#ifndef MAP_H_
#define MAP_H_

#include "Estrada.h"
#include "node.h"
#include "graphviewer.h"


class Map {
private:
	GraphViewer graphviewer;
	std::vector<Node> pontos;
	std::vector<Node> solucao;

public:
	Map (std::vector<Node> pontos);
	void addNode (Node node);
	void addEstrada (Estrada estrada, Node init, Node dest);
	void solution ();
	void dijkstra (Node init, Node dest);
};


#endif
