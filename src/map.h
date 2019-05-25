#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include <limits>
#include <queue>
#include <list>
#include <cmath>
#include "MutablePriorityQueue.h"

#include "Estrada.h"
#include "node.h"
#include "graphviewer.h"

#define INF std::numeric_limits<double>::max()

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
	std::vector<Node*> getInterece();
	std::vector<Node*> getSolucao();
	std::vector<Estrada*> getEstradas();
	void addPontoInterece (Node* node);
	void removePontoInterece (Node* node);
	void solution ();
	double dijkstra (Node* init, Node* dest);
	bool pesoMelhor (Node* nodeCandidato, Node* nodeVizinho, double peso);
	void inicializacaoDijkstra(Node* pontoInicial);
	void exit();
};


#endif
