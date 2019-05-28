#include "VETV.h"

/*FUNCTIONS FOR CLASS VETV*/

/**
 * @brief      Constructs the object.
 *
 * @param  tipo     	      The type of the VETV.
 * @param  pontoInicial	    The initial point of the VETV.
 */
VETV::VETV(Tipo tipo, Node* pontoInicial) {
	this->tipo = tipo;
	this->pontoInicial = pontoInicial;
}

/**
* @brief      Sets the type of the VETV.
*/
void VETV::setTipo(Tipo tipo) {
	this->tipo = tipo;
}

/**
* @brief      Gets the type of the VETV.
*
* @return     The type of the VETV.
*/
Tipo VETV::getTipo() {
	return this->tipo;
}

/**
* @brief      Sets the initial point of the VETV.
*/
void VETV::setPontoInicial(Node* node) {
	this->pontoInicial = node;
}

/**
* @brief      Gets the initial point of the VETV.
*
* @return     The initial point of the VETV.
*/
Node* VETV::getPontoInicail() {
	return this->pontoInicial;
}

/**
* @brief      Sets the way of the VETV.
*/
void VETV::setCaminho(std::vector<Node*> nodes) {
	this->caminho = nodes;
}


/**
* @brief      Gets the way of the VETV.
*
* @return     The way of the VETV.
*/
std::vector<Node*> VETV::getCaminho() {
	return this->caminho;
}
