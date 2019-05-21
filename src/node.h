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
		std::vector<Estrada> estradas;
		bool visited;

		void addEstrada(Node *dest, double peso);
		bool removeEdgeTo(Node *dest);
public:
		Node(float x, float y, int id, Tipo tipo);

		std::vector<Estrada> getEstradas();
		void addEstrada (Estrada estrada);
		int getId();
		Tipo getTipo();
		float getX();
		float getY();
		bool isVisited();
		void setVisited();
};








#endif
