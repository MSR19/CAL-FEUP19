#include "map.h"
#include "graphviewer.h"


void Map::addNode (int id, float x, float y, Tipo tipo) {
	Node* novo = new Node(x, y, id, tipo);
	this->pontos.push_back(novo);

	Tipo tip = NONE;
	if (tipo != tip) {
		this->interece.push_back(novo);
	}
}

bool Map::addEstrada (int id, int nodeIdInicio, int nodeIdDestino) {
	Node* inicio = NULL;
	Node* destino = NULL;
	bool x = true;
	bool y = true;

	for (unsigned int i = 0; i != this->pontos.size(); i++) {

		if (this->pontos[i]->getId() == nodeIdInicio) {
			x = false;
			inicio = this->pontos[i];
		}

		if (this->pontos[i]->getId() == nodeIdDestino) {
			y = false;
			destino = this->pontos[i];
		}

	}

	if (x || y) {
		return false;
	}
	else
	{
	Estrada nova = Estrada(id, inicio, destino);
	this->estradas.push_back(&nova);
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
	this->pontos.push_back(new Node(5000, 0, 0, NONE));

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
		gv->addNode(pontos[i]->getId(), pontos[i]->getX()-menorX, pontos[i]->getY()-menorY);
	}


	int i = 0;
	while (getline(fileEdge,edges)) {

		int idNodeInit;
		int idNodeDest;

		sscanf (edges.c_str(),"(%d,%d)",&idNodeInit, &idNodeDest);

		if (this->addEstrada(i, idNodeInit, idNodeDest))
			gv->addEdge(i,idNodeInit,idNodeDest,0);
		i++;

	}

}

std::vector<Node*> Map::getPontos() {
	return this->pontos;
}

std::vector<Node*> Map::getInterece() {
	return this->interece;
}

std::vector<Node*> Map::getSolucao() {
	return this->solucao;
}

std::vector<Estrada*> Map::getEstradas() {
	return this->estradas;
}

void Map::addPontoInterece (Node* node) {
	this->interece.push_back(node);
}

void Map::removePontoInterece (Node* node) {
	for (unsigned int i = 0; i != this->interece.size(); i++) {
		cout << interece[i]->getId() << endl;
		if (this->interece[i] == node) {
			this->interece.erase(this->interece.begin()+i);
		}
	}
}

void Map::solution () {

}

double Map::dijkstra (Node* init, Node* dest) {
	this->inicializacaoDijkstra(init);
	MutablePriorityQueue<Node> q;
	q.insert(init);
	while ( ! q.empty() ) {
		Node* v = q.extractMin();
		for (Estrada e : v->getEstradas()) {
			double arrestaPeso = e.getPeso();
			if ( pesoMelhor(v, e.getDestino(), e.getPeso())) {
				if (arrestaPeso == INF)
					q.insert(e.dest);
				else
					q.decreaseKey(e.dest);
			}
		}
	}

	return dest->getPeso();
}

std::vector<Node*> Map::getCaminho(Node* init, Node* dest) {
	vector<Node*> solucaoTemporaria;
	if (dest->getPeso() == INF)
		return solucaoTemporaria;
	for ( ; dest != nullptr; dest = dest->getCaminho())
		solucaoTemporaria.push_back(dest);
	reverse(solucaoTemporaria.begin(), solucaoTemporaria.end());
	return solucaoTemporaria;
}

bool Map::pesoMelhor (Node* nodeVisitado, Node* nodeVizinho, double pesoArresta) {
	if (nodeVizinho->getPeso() > pesoArresta + nodeVizinho->getPeso()) {
		nodeVizinho->setPeso(pesoArresta + nodeVizinho->getPeso());
		nodeVizinho->setCaminho(nodeVisitado);
		return true;
	}
	else
		return false;
}

void Map::inicializacaoDijkstra(Node* pontoInicial) {
	for (Node* node : this->pontos) {
		node->setCaminho(nullptr);
		node->setPeso(INF);
	}
	pontoInicial->setPeso(0);
}

void Map::exit() {
	this->graphviewer->closeWindow();
}



