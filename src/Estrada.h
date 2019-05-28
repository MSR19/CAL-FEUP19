/*
 *@file Estrada.h
 *@brief header file containing the declaration of class Estrada.
 */
 
#ifndef _ESTRADA_H_
#define _ESTRADA_H_

#include <cmath>
#include "node.h"

class Node;

class Estrada {
	int id;
	Node* ini;
	Node* dest;
	double peso;
public:
	Estrada(int id, Node* ini,Node *dest);
	Node* getInicio();
	Node* getDestino();
	double getPeso();
};


#endif
