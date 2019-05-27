#ifndef	VETV_H_
#define VETV_H_

#include "node.h"



class VETV {
private:
	Tipo tipo;
	std::vector<Node*> caminho;
	Node* pontoInicial;

public:
	void setTipo(Tipo tipo);
	Tipo getTipo();

	void setPontoInicial(Node* node);
	Node* getPontoInicail();

	void setCaminho(std::vector<Node*> nodes);
	std::vector<Node*> getCaminho();
};

























#endif
