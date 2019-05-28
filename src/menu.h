#ifndef MENU_H_
#define MENU_H_

#include "map.h"
#include <iostream>

class Menu {
private:
	Map* map;
	bool firstIteration = true;

	void changeNodesInVector(std::vector<Node* > nodes);
	void showNodes(std::vector<Node* > nodes);
	void showTipo(Node* node);
	string srtingHandler ();
	int intHandler (int max);
	void chageNode(int nodeVectorPos);
	void setSecondIteration();
	bool IsOnFirstIteration();
	void carBanks();
	void carMuseums();
	void carMails();
	void carCouncils();
public:
	bool Banks=false;
	bool Museums=false;
	bool Mails=false;
	bool Councils=false;

	Menu ();
	void initialMenu();
	void loadMap();
	void showSolution();
	void multipleCars();
};

#endif
