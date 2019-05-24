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

bool Map::addEstrada (int id, int nodeIdInicio, int nodeIdDestino) {
	Node inicio = Node(0,0,0,NONE);
	Node destino = inicio;
	bool x = true;
	bool y = true;

	for (unsigned int i = 0; i != this->pontos.size(); i++) {

		if (this->pontos[i].getId() == nodeIdInicio) {
			x = false;
			inicio = this->pontos[i];
		}

		if (this->pontos[i].getId() == nodeIdDestino) {
			y = false;
			destino = this->pontos[i];
		}

	}

	if (x || y) {
		return false;
	}
	else
	{
	Estrada nova = Estrada(id, &inicio, &destino);
	this->estradas.push_back(nova);
	return true;
	}

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

	//Opening files
	ifstream fileNode;
	fileNode.open(nodes, ios::in);
	if (!fileNode.good()) {
		cout << "File node failed to open" << endl;
		return;
	}
	getline(fileNode,nodes);

	ifstream fileEdge;
	fileEdge.open(edges, ios::in);
	if (!fileEdge.good()) {
		cout << "File edge failed to open" << endl;
		return;
	}
	getline(fileEdge,edges);

	unsigned int menorX = -1;
	unsigned int menorY = -1;
	while (getline(fileNode,nodes)) {
		int id;
		float x;
		float y;
		sscanf (nodes.c_str(),"(%d,%f,%f)",&id, &x, &y);
		this->addNode(id,x, y, NONE);
		if (menorX > x)
			menorX = x;
		if (menorY > y)
			menorY = y;
	}

	for (unsigned int i = 0; i != pontos.size(); i++) {
		gv->addNode(pontos[i].getId(), pontos[i].getX()-menorX, pontos[i].getY()-menorY);
	}


	int i = 0;
	while (getline(fileEdge,edges)) {

		int idNodeInit;
		int idNodeDest;

		sscanf (edges.c_str(),"(%d,%d)",&idNodeInit, &idNodeDest);

		if (this->addEstrada(i, idNodeInit, idNodeDest))
			gv->addEdge(i,idNodeInit,idNodeDest,0);
		i++;
		cout << edges << endl << idNodeInit << "/" << idNodeDest << endl << i << "Isto vai dar merda!" << endl;
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





