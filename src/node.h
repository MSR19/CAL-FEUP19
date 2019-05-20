#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include <string>

class Estrada;

enum Tipo {
	BANCOS,
	MUSEUS,
	CORREIO_URGENTE,
	JUNTAS
};

class Node {
private:
		std::string nome;
		Tipo tipo;
		std::vector<Estrada> estradas;
		bool visited;

		void addEstrada(Node *dest, double peso);
		bool removeEdgeTo(Node *dest);
public:
		Node(std::string nome, Tipo tipo, std::vector<Estrada> estradas);
		Node(std::string nome, Tipo tipo);

		std::vector<Estrada> getEstradas();
		std::string getNome();
		Tipo getTipo();
		bool isVisited();
		void setVisited();
};








#endif
