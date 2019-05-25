#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include "Estrada.h"

class Estrada;

enum Tipo {
	BANCOS,
	MUSEUS,
	CORREIO_URGENTE,
	JUNTAS,
	NONE,
};

class Node {
private:
		int id;
		Tipo tipo;
		float x, y;
		double peso;
		std::vector<Estrada> estradas;
		bool visited;

		void addEstrada(Node *dest, double peso);
		bool removeEdgeTo(Node *dest);
		Node* caminho = NULL;
		int queueIndex = 0; // required by MutablePriorityQueue
public:
		Node(float x, float y, int id, Tipo tipo);

		std::vector<Estrada> getEstradas();
		void addEstrada (Estrada estrada);
		int getId();
		Tipo getTipo();
		void setTipo (Tipo tipo);
		float getX();
		float getY();
		bool isVisited();
		void setVisited(bool visited);
		double getPeso();
		void setPeso(double peso);
		Node* getCaminho();
		void setCaminho(Node* caminho);
		int getQueueIndex();
		void setQueueIndex(int index);
};








#endif
