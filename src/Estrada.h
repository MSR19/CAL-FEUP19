#ifndef _ESTRADA_H_
#define _ESTRADA_H_

#include <string>

class Node;

class Estrada {
	std::string nome;
	Node* ini;
	Node* dest;
	double peso;
public:
	Estrada(std::string nome, Node* ini,Node *dest, double peso);
	std::string getNome();
	Node* getInicio();
	Node* getDestino();
	double getPeso();
};


#endif
