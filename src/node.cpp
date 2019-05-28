#include "node.h"

/*FUNCTIONS FOR CLASS NODE*/

/**
 * @brief      Constructs the object.
 *
 * @param  x     	The x coordinate of the Node.
 * @param  y	    The y coordinate of the Node.
 * @param  id    	The id of the Node.
 * @param  Tipo		The type of the Node.
 */
Node::Node(float x, float y, int id, Tipo tipo) {
	this->x = x;
	this->y = y;
	this->id = id;
	this->tipo = tipo;
	this->visited = false;
}

/**
* @brief      Gets the roads that leave this Node.
*
* @return     The rodes that leave this Node.
*/
std::vector<Estrada> Node::getEstradas() {
	return this->estradas;
}

/**
* @brief      Function to add a road to the roads.
*/
void Node::addEstrada (Estrada estrada) {
	this->estradas.push_back(estrada);
}

/**
* @brief      Gets the id of the Node.
*
* @return     The id of the Node.
*/
int Node::getId() {
	return this->id;
}

/**
* @brief      Gets the x coordinate of the Node.
*
* @return     The x coordinate of the Node.
*/
float Node::getX() {
	return this->x;
}

/**
* @brief      Gets the y coordinate of the Node.
*
* @return     The y coordinate of the Node.
*/
float Node::getY() {
	return this->y;
}

/**
* @brief      Gets the type of the Node.
*
* @return     The type of the Node.
*/
Tipo Node::getTipo() {
	return this->tipo;
}

/**
* @brief      Sets the type of the Node.
*/
void Node::setTipo(Tipo tipo) {
	this->tipo = tipo;
}

/**
 * @brief     Gets the information if the Node is visited.
 *
 * @return     If the Node is visited(true) or not(false).
 */
bool Node::isVisited() {
	return this->visited;
}

/**
* @brief      Sets the boolean visited of the Node.
*/
void Node::setVisited(bool visited) {
	this->visited = visited;
}

/**
* @brief      Gets the weight of the Node.
*
* @return     The weight of the Node.
*/
double Node::getPeso() const{
	return this->peso;
}

/**
* @brief      Sets the weight of the Node.
*/
void Node::setPeso(double peso) {
	this->peso = peso;
}

/**
* @brief      Gets the way of the Node.
*
* @return     The way of the Node.
*/
Node* Node::getCaminho() {
	return this->caminho;
}

/**
* @brief      Sets the way of the Node.
*/
void Node::setCaminho(Node* caminho) {
	this->caminho = caminho;
}

/**
 * @brief     Operador than less.
 *
 * @return    If the Node is lighter than another(true) or not(false).
 */
bool Node::operator<(Node& vertex) const {
	return this->getPeso() < vertex.getPeso();
}
