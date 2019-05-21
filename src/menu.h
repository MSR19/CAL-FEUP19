#ifndef MENU_H_
#define MENU_H_

#include "map.h"
#include <iostream>

class Menu {
private:
	Map map;

	string srtingHandler ();
	int intHandler (int max);
public:
	Menu ();
	void InitialMenu();
	void LoadMap();
	void ReformatingMap();
	void ShowSolution();
};

#endif
