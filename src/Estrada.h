#ifndef _ESTRADA_H_
#define _ESTRADA_H_

#include <string>

class Node;

class Estrada {
	std::string nome;
	Node * dest;
	double peso;
public:
	Estrada(std::string nome, Node *dest, double peso);
	std::string getNome();
	Node getDestino();
	double getPeso();
};


#endif
