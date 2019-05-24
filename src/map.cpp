#include "map.h"
#include "graphviewer.h"


void Map::addNode (int id, float x, float y, Tipo tipo) {
	Node novo = Node(x, y, id, tipo);
	this->pontos.push_back(novo);

	Tipo tip = NONE;
	if (tipo != tip) {
		this->interece.push_back(novo);
	}
}

void Map::addEstrada (int id, int nodeIdInicio, int nodeIdDestino) {
	Node* inicio = NULL;
	Node* destino = NULL;

	for (unsigned int i = 0; i != this->pontos.size(); i++) {

		if (this->pontos[i].getId() == nodeIdInicio)
			*inicio = this->pontos[i];

		if (this->pontos[i].getId() == nodeIdDestino)
			*destino = this->pontos[i];

	}

	Estrada nova = Estrada(id, inicio, destino);
	this->estradas.push_back(nova);
}

Map::Map (string cidade) {

	GraphViewer *gv = new GraphViewer(500, 500,false);
	graphviewer = gv;
	gv->createWindow(5000, 5000);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("green");

	gv->addNode(5000,0,0);
	this->pontos.push_back(Node(5000, 0, 0, NONE));

	string edges = "/T08_edges_";
	string nodes = "/T08_nodes_X_Y_";

	string auxS = "./T08/";
	string auxS2 = ".txt";

	edges = auxS + cidade + edges + cidade + auxS2;
	nodes = auxS + cidade + nodes + cidade + auxS2;

	std::cout << "Isto da merda?" << endl;
	int fileNodes = open(nodes.c_str(), O_RDONLY);
	if (fileNodes == -1) {
		std::cout << "File nodes did not open! closing the map!" << endl;
		return;
	}
	else {
		std::cout << "File Open nodes!" << endl;
	}

	int fileEdges = open(edges.c_str(), O_RDONLY);
	if (fileEdges == -1) {
		std::cout << "File edges did not open! closing the map!" << endl;
		return;
	}
	else {
		std::cout << "File Open edges!" << endl;
	}

	int i = 0;
	char buffer [500] = "";
	while (read(fileNodes, &buffer, sizeof(buffer)) > 0) {
		int id;
		float x;
		float y;
		sscanf (buffer,"(%d,%f,%f)",&id, &x, &y);

		if (i%1000 == 0)
			this->addNode(id,x, y, BANCOS);
		else
			this->addNode(id,x, y, NONE);

		gv->addNode(id, x, y);
		i++;
		cout << "reading " << i << " ! X:" << x << " / Y:" << y << " /" << endl;
	}

	i = 0;
	while (read(fileEdges, &buffer, sizeof(buffer)) > 0) {
		int idNodeInit;
		int idNodeDest;

		sscanf (buffer,"(%d,%d)", &idNodeInit, &idNodeDest);

		this->addEstrada(i, idNodeInit, idNodeDest);
		gv->addEdge(i,idNodeInit,idNodeDest,0);
		i++;
	}

}

std::vector<Node> Map::getPontos() {
	return this->pontos;
}

std::vector<Node> Map::getSolucao() {
	return this->solucao;
}

std::vector<Estrada> Map::getEstradas() {
	return this->estradas;
}

void Map::solution () {

}

void Map::dijkstra (Node init, Node dest) {

}





