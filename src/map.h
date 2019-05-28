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
#include <algorithm>
#include "MutablePriorityQueue.h"

#include "Estrada.h"
#include "node.h"
#include "graphviewer.h"
#include "VETV.h"

#define INF std::numeric_limits<double>::max()

class Map {
private:
	GraphViewer* graphviewer;
	std::vector<Node*> pontos;
	std::vector<Node*> interece;
	std::vector<Estrada*> estradas;
	std::vector<Node*> solucao;
	std::vector<VETV* > carros;

	std::vector<Node*> intereceBanks;
	std::vector<Node*> intereceMuseums;
	std::vector<Node*> intereceMails;
	std::vector<Node*> intereceCouncils;


	void addNode (int id, float x, float y, Tipo tipo);
	bool addEstrada (int id, int nodeIdInicio, int nodeIdDestino);
public:
	Map (string cidade);
	std::vector<Node*> getPontos();
	std::vector<Node*> getInterece();
	std::vector<Node*> getIntereceBanks();
	std::vector<Node*> getIntereceMuseums();
	std::vector<Node*> getIntereceMails();
	std::vector<Node*> getIntereceCouncils();
	std::vector<Node*> getSolucao();
	std::vector<Estrada*> getEstradas();
	void setSolucao(std::vector<Node*> vec);
	void addPontoInterece (Node* node);
	void addPontoIntereceBanks (Node* node);
	void addPontoIntereceMuseums (Node* node);
	void addPontoIntereceMails (Node* node);
	void addPontoIntereceCouncils (Node* node);
	void removePontoInterece (Node* node);
	void solution (Node* pontoInicial, bool Banks, bool Museums, bool Mails, bool Councils);
	double dijkstra (Node* init, Node* dest);
	std::vector<Node*> getCaminho(Node* init, Node* dest);
	bool pesoMelhor (Node* nodeCandidato, Node* nodeVizinho, double peso);
	void inicializacaoDijkstra(Node* pontoInicial);
	void iluminaSolucaoMapa();
	void exit();
};


#endif
