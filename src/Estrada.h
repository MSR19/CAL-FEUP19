

#ifndef _ESTRADA_H_
#define _ESTRADA_H_

class Node;

class Estrada {
	String nome;
	Node * dest;
	double peso;
public:
	Estrada(String nome, Node *dest, double peso);
	String getNome();
	Node getDestino();
	double getPeso();
};


#endif
