/*
 *@file VETV.h
 *@brief header file containing the declaration of class VETV.
 */
#ifndef	VETV_H_
#define VETV_H_

#include "node.h"



class VETV {
private:
	Tipo tipo;
	std::vector<Node*> caminho;
	Node* pontoInicial;

public:
	VETV(Tipo tipo, Node* pontoInicial);

	void setTipo(Tipo tipo);
	Tipo getTipo();

	void setPontoInicial(Node* node);
	Node* getPontoInicail();

	void setCaminho(std::vector<Node*> nodes);
	std::vector<Node*> getCaminho();
};

























#endif
