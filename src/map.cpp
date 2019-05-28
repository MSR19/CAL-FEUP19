#include "map.h"
#include "graphviewer.h"

void Map::addNode(int id, float x, float y, Tipo tipo)
{
	Node *novo = new Node(x, y, id, tipo);
	this->pontos.push_back(novo);

	Tipo tip = NONE;
	if (tipo != tip)
	{
		this->interece.push_back(novo);
	}
}

bool Map::addEstrada(int id, int nodeIdInicio, int nodeIdDestino)
{
	Node *inicio = NULL;
	Node *destino = NULL;
	bool x = true;
	bool y = true;

	for (unsigned int i = 0; i != this->pontos.size(); i++)
	{

		if (this->pontos[i]->getId() == nodeIdInicio)
		{
			x = false;
			inicio = this->pontos[i];
		}

		if (this->pontos[i]->getId() == nodeIdDestino)
		{
			y = false;
			destino = this->pontos[i];
		}
	}

	if (x || y)
	{
		return false;
	}
	else
	{
		Estrada novainit = Estrada(id, inicio, destino);
		this->estradas.push_back(&novainit);
		inicio->addEstrada(novainit);
		Estrada novadest = Estrada(id, destino, inicio);
		this->estradas.push_back(&novadest);
		destino->addEstrada(novadest);

		return true;
	}
}

Map::Map(string cidade)
{
	cout << "É a criar isto?";
	GraphViewer *gv = new GraphViewer(500, 500, false);
	graphviewer = gv;
	gv->createWindow(500, 500);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("green");

	cout << "è";

	string edges = "/T08_edges_";
	string nodes = "/T08_nodes_X_Y_";

	string auxS = "./T08/";
	string auxS2 = ".txt";

	edges = auxS + cidade + edges + cidade + auxS2;
	nodes = auxS + cidade + nodes + cidade + auxS2;

	//Opening files
	ifstream fileNode;
	fileNode.open(nodes, ios::in);
	if (!fileNode.good())
	{
		cout << "File node failed to open" << endl;
		return;
	}
	getline(fileNode, nodes);

	ifstream fileEdge;
	fileEdge.open(edges, ios::in);
	if (!fileEdge.good())
	{
		cout << "File edge failed to open" << endl;
		return;
	}
	getline(fileEdge, edges);

	unsigned int menorX = -1;
	unsigned int menorY = -1;
	while (getline(fileNode, nodes))
	{
		int id;
		float x;
		float y;
		sscanf(nodes.c_str(), "(%d,%f,%f)", &id, &x, &y);
		this->addNode(id, x, y, NONE);
		if (menorX > x)
			menorX = x;
		if (menorY > y)
			menorY = y;
	}

	for (unsigned int i = 0; i != pontos.size(); i++)
	{
		gv->addNode(pontos[i]->getId(), pontos[i]->getX() - menorX, pontos[i]->getY() - menorY);
	}

	int i = 0;
	while (getline(fileEdge, edges))
	{

		int idNodeInit;
		int idNodeDest;

		sscanf(edges.c_str(), "(%d,%d)", &idNodeInit, &idNodeDest);

		if (this->addEstrada(i, idNodeInit, idNodeDest))
			gv->addEdge(i, idNodeInit, idNodeDest, 0);
		i++;
	}
}

std::vector<Node *> Map::getPontos()
{
	return this->pontos;
}

std::vector<Node *> Map::getInterece()
{
	return this->interece;
}

std::vector<Node *> Map::getIntereceBanks()
{
	return this->intereceBanks;
}

std::vector<Node *> Map::getIntereceMuseums()
{
	return this->intereceMuseums;
}

std::vector<Node *> Map::getIntereceMails()
{
	return this->intereceMails;
}

std::vector<Node *> Map::getIntereceCouncils()
{
	return this->intereceCouncils;
}

std::vector<Node *> Map::getSolucao()
{
	return this->solucao;
}

void Map::setSolucao(std::vector<Node *> vec)
{
	this->solucao = vec;
}

std::vector<Estrada *> Map::getEstradas()
{
	return this->estradas;
}

void Map::addPontoInterece(Node *node)
{
	this->interece.push_back(node);
}

void Map::addPontoIntereceBanks(Node *node)
{
	this->intereceBanks.push_back(node);
}

void Map::addPontoIntereceMuseums(Node *node)
{
	this->intereceMuseums.push_back(node);
}

void Map::addPontoIntereceMails(Node *node)
{
	this->intereceMails.push_back(node);
}

void Map::addPontoIntereceCouncils(Node *node)
{
	this->intereceCouncils.push_back(node);
}

void Map::removePontoInterece(Node *node)
{
	for (unsigned int i = 0; i != this->interece.size(); i++)
	{
		cout << interece[i]->getId() << endl;
		if (this->interece[i] == node)
		{
			this->interece.erase(this->interece.begin() + i);
		}
	}
}

void Map::solution(Node *pontoInicial, bool Banks, bool Museums, bool Mails, bool Councils)
{
	std::vector<Node *> solucaoTemporaria = {};
	Node *final = nullptr;
	double pesoMenor = INF;

	if (Banks)
	{
		for (unsigned int i = 0; i != this->intereceBanks.size(); i++)
		{
			if (!this->intereceBanks[i]->isVisited())
			{
				if (pesoMenor > this->dijkstra(pontoInicial, intereceBanks[i]))
				{
					solucaoTemporaria = this->getCaminho(pontoInicial, intereceBanks[i]);
					final = intereceBanks[i];
				}
			}
		}
	}
	else if (Museums)
	{
		for (unsigned int i = 0; i != this->intereceMuseums.size(); i++)
		{
			if (!this->intereceMuseums[i]->isVisited())
			{
				if (pesoMenor > this->dijkstra(pontoInicial, intereceMuseums[i]))
				{
					solucaoTemporaria = this->getCaminho(pontoInicial, intereceMuseums[i]);
					final = intereceMuseums[i];
				}
			}
		}
	}
	else if (Mails)
	{
		for (unsigned int i = 0; i != this->intereceMails.size(); i++)
		{
			if (!this->intereceMails[i]->isVisited())
			{
				if (pesoMenor > this->dijkstra(pontoInicial, intereceMails[i]))
				{
					solucaoTemporaria = this->getCaminho(pontoInicial, intereceMails[i]);
					final = intereceMails[i];
				}
			}
		}
	}
	else if (Councils)
	{
		for (unsigned int i = 0; i != this->intereceCouncils.size(); i++)
		{
			if (!this->intereceCouncils[i]->isVisited())
			{
				if (pesoMenor > this->dijkstra(pontoInicial, intereceCouncils[i]))
				{
					solucaoTemporaria = this->getCaminho(pontoInicial, intereceCouncils[i]);
					final = intereceCouncils[i];
				}
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i != this->interece.size(); i++)
		{
			if (!this->interece[i]->isVisited())
			{
				if (pesoMenor > this->dijkstra(pontoInicial, interece[i]))
				{
					solucaoTemporaria = this->getCaminho(pontoInicial, interece[i]);
					final = interece[i];
				}
			}
		}
	}

	if (final != nullptr)
	{
		final->setVisited(true);

		if (this->solucao.size() > 0 && solucaoTemporaria.size() > 0)
		{
			if (this->solucao.size() > 1)
				this->solucao.insert(this->solucao.end(), solucaoTemporaria.begin() + 1, solucaoTemporaria.end());
			this->solution(final, Banks, Museums, Mails, Councils);
		}
		else if (this->solucao.size() == 0)
		{
			this->solucao = solucaoTemporaria;
			this->solution(final, Banks, Museums, Mails, Councils);
		}
	}
	else
	{
		this->iluminaSolucaoMapa(Banks, Museums, Mails, Councils);
	}
}

double Map::dijkstra(Node *init, Node *dest)
{
	this->inicializacaoDijkstra(init);
	MutablePriorityQueue<Node> q;
	q.insert(init);
	while (!q.empty())
	{
		Node *v = q.extractMin();
		for (Estrada e : v->getEstradas())
		{
			double arrestaPeso = e.getDestino()->getPeso();
			if (pesoMelhor(v, e.getDestino(), e.getPeso()))
			{
				if (arrestaPeso == INF)
					q.insert(e.getDestino());
				else
					q.decreaseKey(e.getDestino());
			}
		}
	}
	return dest->getPeso();
}

std::vector<Node *> Map::getCaminho(Node *init, Node *dest)
{
	std::vector<Node *> solucaoTemporaria;
	if (dest->getPeso() == INF)
		return solucaoTemporaria;
	for (; dest != nullptr; dest = dest->getCaminho())
		solucaoTemporaria.push_back(dest);
	solucaoTemporaria.push_back(init);
	reverse(solucaoTemporaria.begin(), solucaoTemporaria.end());
	return solucaoTemporaria;
}

bool Map::pesoMelhor(Node *nodeVisitado, Node *nodeVizinho, double pesoArresta)
{

	if (nodeVizinho->getPeso() > pesoArresta + nodeVisitado->getPeso())
	{
		nodeVizinho->setPeso(pesoArresta + nodeVisitado->getPeso());
		nodeVizinho->setCaminho(nodeVisitado);
		return true;
	}
	else
	{

		return false;
	}
}

void Map::inicializacaoDijkstra(Node *pontoInicial)
{
	for (Node *node : this->pontos)
	{
		node->setCaminho(nullptr);
		node->setPeso(INF);
	}

	pontoInicial->setPeso(0);
}

void Map::iluminaSolucaoMapa(bool Banks, bool Museums, bool Mails, bool Councils)
{
	for (unsigned int i = 0; i != this->solucao.size(); i++)
	{
		if (Banks)
		{
			if (this->solucao[i]->getTipo() == BANCOS)
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "GREEN");
			else if (this->solucao[i]->getTipo() != MUSEUS && this->solucao[i]->getTipo() != CORREIO_URGENTE && this->solucao[i]->getTipo() != JUNTAS)
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "CYAN");
			}
		}
		else if (Museums)
		{
			if (this->solucao[i]->getTipo() == MUSEUS)
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "ORANGE");
			else if (this->solucao[i]->getTipo() != BANCOS && this->solucao[i]->getTipo() != CORREIO_URGENTE && this->solucao[i]->getTipo() != JUNTAS)
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "YELLOW");
			}
		}
		else if (Mails)
		{
			if (this->solucao[i]->getTipo() == CORREIO_URGENTE)
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "RED");
			else if (this->solucao[i]->getTipo() != BANCOS && this->solucao[i]->getTipo() != MUSEUS && this->solucao[i]->getTipo() != JUNTAS)
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "PINK");
			}
		}
		else if (Councils)
		{
			if (this->solucao[i]->getTipo() == JUNTAS)
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "DARK_GRAY");
			else if (this->solucao[i]->getTipo() != BANCOS && this->solucao[i]->getTipo() != MUSEUS && this->solucao[i]->getTipo() != CORREIO_URGENTE)
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "LIGHT_GRAY");
			}
		}
		else
		{
			if (this->solucao[i]->getTipo() == BANCOS || this->solucao[i]->getTipo() == MUSEUS || this->solucao[i]->getTipo() == CORREIO_URGENTE || this->solucao[i]->getTipo() == JUNTAS)
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "BLACK");
			}
			else
			{
				this->graphviewer->setVertexColor(this->solucao[i]->getId(), "WHITE");
			}
		}
	}
}

void Map::exit()
{
	this->graphviewer->closeWindow();
}
