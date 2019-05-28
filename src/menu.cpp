#include "menu.h"
using namespace std;
Menu::Menu() {
	this->map = NULL;
}

int Menu::intHandler (int max)
{
	int choice;
	bool inputError;
	do
	{
		inputError = false;
		std::cin >> choice;
		if (std::cin.fail() || !(choice >= 1 && choice <= max)) {
			std::cin.clear(); //clear cin flags
			std::cin.ignore(100000, '\n'); //ignore caracters
			inputError = true; //sets to true so loop repeats
			std::cout << std::endl <<"Input failed: try again!" << std::endl;
		}
	} while (inputError); //if error, loop repeats
	std::cin.ignore(10000, '\n');
	return choice;
}

std::string Menu::srtingHandler()
{
	std::string choice;
	bool inputError;
	do
	{
		inputError = false;
		getline(cin, choice);
		if (cin.fail())
		{
			cin.ignore(100000, '\n');
			cin.clear();
			inputError = true;
			cout << "Input failed: try again!";
		}
	} while (inputError);
	//cin.ignore(10000, '\n');

	return choice;
}

void Menu::initialMenu() {
	int answer;
	do {



std::cout << R"(
  _      __    __                  
 | | /| / /__ / /______  __ _  ___ 
 | |/ |/ / -_) / __/ _ \/  ' \/ -_)
 |__/|__/\__/_/\__/\___/_/_/_/\__/ 
               __             
              / /____   
             / __/ _ \ 
             \__/\___/  
    ____                 _ __      
   / __/__ ______ ______(_) /___ __
  _\ \/ -_) __/ // / __/ / __/ // /
 /___/\__/\__/\_,_/_/ /_/\__/\_, / 
                            /___/  
  _   __                     _____                        __
 | | / /__ ____    ___ ___  / _/ /__    _____ ________   / /
 | |/ / _ `/ _ \  (_-</ _ \/ _/ __/ |/|/ / _ `/ __/ -_) /_/ 
 |___/\_,_/_//_/ /___/\___/_/ \__/|__,__/\_,_/_/  \__/ (_)                                                                                                                                                
)" << endl;                            
	std::cout << "What do you wish to do?" << endl;
	std::cout << "1: Load the map" << endl;
	std::cout << "2: Change the type of nodes" << endl;
	std::cout << "3: View especial nodes" << endl;
	std::cout << "4: View the shortest way" << endl;
	std::cout << "5: Add new car to the list" << endl;
	std::cout << "6: View the shortest way to the cars" << endl;
	std::cout << "7: quit" << endl << endl;

	std::cout << "Chose the option you want: ";
	answer = this->intHandler(7);

	switch (answer) {
	case 1:
		this->loadMap();
		break;
	case 2:
		if (this->map != NULL)
			this->changeNodesInVector(this->map->getPontos());
		else
			std::cout << endl << "you need to load a map first!" << endl;
		break;
	case 3:
		if (this->map != NULL)
			this->changeNodesInVector(this->map->getInterece());
		else
			std::cout << endl << "you need to load a map first!" << endl;
		break;
	case 4:
		if (this->map != NULL)
			this->showSolution();
		else {
			std::cout << endl << "you need to load a map first!" << endl;
		}
		break;
	case 5:
		if (this->map != NULL)
			this->addCaro();
		else
			std::cout << endl << "you need to load a map first!" << endl;
		break;
	case 6:
		if (this->map != NULL)
			this->showSolution2();
		else {
			std::cout << endl << "you need to load a map first!" << endl;
		}
		break;

	case 7:
		std::cout << endl << "Thank you for your preference!" << endl;
		this->map->exit();
		break;
	}
	} while(answer != 7);
}

void Menu::loadMap() {
	if (this->map == NULL) {
		std::cout << endl << "Chose a city to load" << endl;
		std::cout << "1: Aveiro" << endl;
		std::cout << "2: Braga" << endl;
		std::cout << "3: Coimbra" << endl;
		std::cout << "4: Ermensinde" << endl;
		std::cout << "5: Fafe" << endl;
		std::cout << "6: Gondomar" << endl;
		std::cout << "7: Lisboa" << endl;
		std::cout << "8: Maia" << endl;
		std::cout << "9: Porto" << endl;
		std::cout << "10: Viseu" << endl << endl;

		std::cout << "Chose the city you want: ";
		int anwer1 = this->intHandler(10);

		//Initializes the map to the corresponding city
		std::vector<string> cidades = {"","Aveiro","Braga","Coimbra","Ermesinde","Fafe","Gondomar","Lisboa", "Maia", "Porto", "Viseu"};
		this->map = new Map(cidades[anwer1]);

	}
	else {
		std::cout << endl << "You have already loaded a map, please restart the program to use a different map!" << endl;
	}
}

void Menu::changeNodesInVector(std::vector<Node* > nodes) {
	std::cout << "The nodes are the following" << endl;
	this->showNodes(nodes);
	std::cout << endl << "Chose the node that you want to alter (use the first number): ";
	int node = this->intHandler(nodes.size());
	this->chageNode(node-1);
}

void Menu::chageNode(int nodeVectorPos) {
	std::vector<Node*> nodes = this->map->getPontos();
	std::cout << "(Id)" << nodes[nodeVectorPos]->getId() << ", (X)" << nodes[nodeVectorPos]->getX() << ", (Y)" << nodes[nodeVectorPos]->getY() << " ,(Type) ";
	this->showTipo(nodes[nodeVectorPos]);

	std::cout << endl << "Chose what to alter:" << endl;
	std::cout << "1: Change type" << endl;
	std::cout << "2: Go back" << endl;

	int anwer = this->intHandler(2);

	if (1 == anwer) {
		cout << endl << "Which of the following types do you want?" << endl;
		cout << "1: NONE" << endl;
		cout << "2: BANCOS" << endl;
		cout << "3: MUSEUS" << endl;
		cout << "4: CORREIO_URGENTE" << endl;
		cout << "5: JUNTAS" << endl << endl;
		cout << "Chose the type you want: ";
		int anwer = this->intHandler(5);
		switch (anwer) {
		case 1:
			if (this->map->getPontos()[nodeVectorPos]->getTipo() != NONE)
				this->map->removePontoInterece(this->map->getPontos()[nodeVectorPos]);
			this->map->getPontos()[nodeVectorPos]->setTipo(NONE);
			break;
		case 2:
			if (this->map->getPontos()[nodeVectorPos]->getTipo() == NONE)
				this->map->addPontoInterece(this->map->getPontos()[nodeVectorPos]);
			this->map->getPontos()[nodeVectorPos]->setTipo(BANCOS);
			break;
		case 3:
			if (this->map->getPontos()[nodeVectorPos]->getTipo() == NONE)
							this->map->addPontoInterece(this->map->getPontos()[nodeVectorPos]);
			this->map->getPontos()[nodeVectorPos]->setTipo(MUSEUS);
			break;
		case 4:
			if (this->map->getPontos()[nodeVectorPos]->getTipo() == NONE)
							this->map->addPontoInterece(this->map->getPontos()[nodeVectorPos]);
			this->map->getPontos()[nodeVectorPos]->setTipo(CORREIO_URGENTE);
			break;
		case 5:
			if (this->map->getPontos()[nodeVectorPos]->getTipo() == NONE)
							this->map->addPontoInterece(this->map->getPontos()[nodeVectorPos]);
			this->map->getPontos()[nodeVectorPos]->setTipo(JUNTAS);
			break;
		}
	}

}

void Menu::showSolution() {
	//Cleans the previus solution
	std::vector<Node*> novaSolucao = {};
	this->map->getSolucao() = novaSolucao;

	//Ask for the initial point and start the alguritm
	std::vector<Node*> nodes = this->map->getPontos();
	this->showNodes(nodes);
	cout << endl << "Chose the node that you want to start (use the first number): ";
	int node = this->intHandler(nodes.size());
	this->map->solution(this->map->getPontos()[node-1]);
	std::vector<Node*> nodeSolucao = this->map->getSolucao();

	//Shows the solution
	cout << "The solution is the following" << endl;
	this->showNodes(nodeSolucao);
	cout << endl << "Write anything to go back to main menu: ";
	string cenas = this->srtingHandler();
}

void Menu::showNodes(std::vector<Node* > nodes) {
	for (unsigned int i = 1; i != nodes.size(); i++) {
		cout << i+1 << ": (Id)" << nodes[i]->getId() << " , (X)" << nodes[i]->getX() << " , (Y)" << nodes[i]->getY() << " , (Type)";
		this->showTipo(nodes[i]);
	}
}

void Menu::showTipo(Node* node) {
	switch (node->getTipo()) {
		case NONE:
			cout << "NONE" << endl;
			break;

		case BANCOS:
			cout << "BANCOS" << endl;
			break;

		case MUSEUS:
			cout << "MUSEUS" << endl;
			break;

		case CORREIO_URGENTE:
			cout << "CORREIO URGENTE" << endl;
			break;

		case JUNTAS:
			cout << "JUNTAS" << endl;
			break;
	}
}

void Menu::addCaro() {

}

void Menu::showSolution2() {

}




