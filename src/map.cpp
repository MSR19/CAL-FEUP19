#include "map.h"

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

	this->graphviewer = GraphViewer(50, 50, false);
	//GraphViewer *gv = new GraphViewer(50, 50, false);
	//gv->createWindow(50, 50);
	//gv->defineVertexColor("blue");
	//gv->defineEdgeColor("green");

	string edges = "T08_edges_";
	string nodes = "T08_nodes_X_Y_";

	edges ="T08/" + cidade +"/"+ edges + cidade + ".txt";
	nodes ="T08/" + cidade +"/"+ nodes + cidade+ ".txt";

	int fileNodes = open(nodes.c_str(), O_RDONLY);
	if (fileNodes == NULL) {
		std::cout << "File nodes did not open! closing the map!" << endl;
		return;
	}

	int fileEdges = open(edges.c_str(), O_RDONLY);
	if (fileEdges == NULL) {
		std::cout << "File edges did not open! closing the map!" << endl;
		return;
	}

	int i = 0;
	char* buffer [500];
	while (read(fileNodes, buffer, sizeof(buffer)) > 0) {
		int id;
		float x;
		float y;
		sscanf (*buffer,"(%d,%f,%f)",&id, &x, &y);

		if (i%10 == 0)
			this->addNode(id,x, y, BANCOS);
		else
			this->addNode(id,x, y, NONE);

		//gv->addNode(id, x, y);
		i++;
	}

	i = 0;
	while (read(fileEdges, buffer, sizeof(buffer)) > 0) {
		int idNodeInit;
		int idNodeDest;

		sscanf (*buffer,"(%d,%d)", &idNodeInit, &idNodeDest);

		this->addEstrada(i, idNodeInit, idNodeDest);
		//gv->addEdge(i,idNodeInit,idNodeDest,0);
		i++;
	}

	//this->graphviewer = *gv;
}






