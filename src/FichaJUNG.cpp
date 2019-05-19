#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
GraphViewer *gv = new GraphViewer(50, 50, false);
gv->createWindow(50, 50);
gv->defineVertexColor("blue");
gv->defineEdgeColor("green");

gv->addNode(0, 2, 2);
gv->addNode(1, 4, 4);
gv->addEdge(2,0,1,0);
}

void exercicio2()
{

}

void exercicio3()
{

}


int main() {
	exercicio1();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
