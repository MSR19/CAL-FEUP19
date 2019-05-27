#ifndef MENU_H_
#define MENU_H_

#include "map.h"
#include <iostream>

class Menu {
private:
	Map* map;

	void showTipo(Node* node);
	string srtingHandler ();
	int intHandler (int max);
public:
	Menu ();
	void initialMenu();
	void loadMap();
	void chageNode(int nodeVectorPos);
	void showSolution();
	void addCaro();
	void showSolution2();
};

#endif
