#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Estrada.h"
#include "node.h"
#include "graphviewer.h"


class Map {
private:
	GraphViewer* graphviewer;
	std::vector<Node*> pontos;
	std::vector<Node*> interece;
	std::vector<Estrada*> estradas;
	std::vector<Node*> solucao;

	void addNode (int id, float x, float y, Tipo tipo);
	bool addEstrada (int id, int nodeIdInicio, int nodeIdDestino);
public:
	Map (string cidade);
	std::vector<Node*> getPontos();
	std::vector<Node*> getSolucao();
	std::vector<Estrada*> getEstradas();
	void solution ();
	void dijkstra (Node init, Node dest);
};


#endif
