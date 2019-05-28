#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "menu.h"

void exercicios();

void exercicios()
{
Menu* menu = new Menu();
menu->initialMenu();
}

int main() {
	exercicios();
	getchar();
	return 0;
}
