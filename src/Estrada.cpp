#include "Estrada.h"


/*FUNCTIONS FOR CLASS ESTRADA*/

/**
 * @brief      Constructs the object.
 *
 * @param  id        The id estrada
 * @param  ini     	 The initial node
 * @param  dest      The destination node
 */

Estrada::Estrada(int id, Node* ini, Node *dest) {
	this->id = id;
	this->ini =ini;
	this->dest = dest;
	float x = dest->getX() - ini->getX();
	float y = dest->getY() - ini->getY();
	this->peso = sqrt((x*x) + (y*y));
}

/**
 * @brief      Gets the initial node.
 *
 * @return     The initial node.
 */
Node* Estrada::getInicio() {
	return this->ini;
}

/**
 * @brief      Gets the destination node.
 *
 * @return     The destination node.
 */
Node* Estrada::getDestino() {
	return this->dest;
}

/**
 * @brief      Gets the weight.
 *
 * @return     The weight.
 */
double Estrada::getPeso() {
	return this->peso;
}
