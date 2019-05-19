#ifndef MAP_H_
#define MAP_H_

#include "Estrada.h"
#include "Node.h"
#include "graphviewer.h"

class Map {
private:
	GraphViewer graphviewer;
	std::vector<Nodes> pontos;
	std::vector<Nodes> solucao;

public:
	Map (std::vector<Nodes> pontos);
	void addNode (Node node);
	void addEstrada (Estrada estrada, Node init, Node dest);
	void solution ();
	void dijkstra (Node init, Node dest);
};


#endif
