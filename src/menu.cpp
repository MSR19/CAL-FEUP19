#include "menu.h"

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
	std::cout << "Welcome to Security Van software" << endl << endl;
	std::cout << "What do you wish to do?" << endl;
	std::cout << "1: Load the map" << endl;
	std::cout << "2: Change the type of nodes" << endl;
	std::cout << "3: View the shortest way" << endl;
	std::cout << "4: quit" << endl << endl;

	std::cout << "Chose the option you want: ";
	answer = this->intHandler(4);

	switch (answer) {
	case 1:
		this->loadMap();
		break;
	case 2:
		if (this->map != NULL) {
		std::vector<Node*> nodes = this->map->getPontos();
		cout << "The nodes are the following" << endl;
		for (unsigned int i = 0; i != nodes.size(); i++) {
			cout << i << ": (Id)" << nodes[i]->getId() << " , (X)" << nodes[i]->getX() << " , (Y)" << nodes[i]->getY() << " , (Type)";
			switch (nodes[i]->getTipo()) {
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
		cout << endl << "Chose the node that you want to alter (use the first number): ";
		int node = this->intHandler(nodes.size());
		this->chageNode(node);
		}
		else {
			std::cout << endl << "you need to load a map first!" << endl;
		}
		break;
	case 3:
		if (this->map != NULL)
			this->showSolution();
		else {
			std::cout << endl << "you need to load a map first!" << endl;
		}
		break;
	case 4:
		std::cout << endl << "Thank you for your preference!" << endl;
		this->map->exit();
		break;
	}
	} while(answer != 4);
}

void Menu::loadMap() {
	if (this->map == NULL) {
		std::cout << endl << "Chose a city to load" << endl;
		std::cout << "1: Aveiro" << endl;
		std::cout << "2: Braga" << endl;
		std::cout << "3: Coimbra" << endl;
		std::cout << "4: Ermensinde" << endl;
		std::cout << "5: Fafe" << endl;
		std::cout << "6: Gondumar" << endl;
		std::cout << "7: Lisboa" << endl;
		std::cout << "8: Maia" << endl;
		std::cout << "9: Porto" << endl;
		std::cout << "10: Viseu" << endl << endl;

		std::cout << "Chose the city you want: ";
		int anwer1 = this->intHandler(10);

		//Initializes the map to the corresponding city
		std::vector<string> cidades = {"","Aveiro","Braga","Coimbra","Ermesinde","Fafe","Gondumar","Lisboa", "Maia", "Porto", "Viseu"};
		this->map = new Map(cidades[anwer1]);

	}
	else {
		std::cout << endl << "You have already loaded a map, please restart the program to use a different map!" << endl;
	}
}

void Menu::chageNode(int nodeVectorPos) {
	std::vector<Node*> nodes = this->map->getPontos();
	std::cout << "What do you want to change?" << endl;
	std::cout << "Node now: (X)" << nodes[nodeVectorPos]->getX() << ", (Y)" << nodes[nodeVectorPos]->getY() << ", (Type)";
	switch (nodes[nodeVectorPos]->getTipo()) {
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
	std::cout << "1: change type" << endl;
	std::cout << "2: bo back" << endl;

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
	//Incerir um ponto inial
	std::vector<Node*> nodes = this->map->getPontos();
	for (unsigned int i = 0; i != nodes.size(); i++) {
		cout << i << ": (Id)" << nodes[i]->getId() << " , (X)" << nodes[i]->getX() << " , (Y)" << nodes[i]->getY() << " , (Type)";
		switch (nodes[i]->getTipo()) {
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
	cout << endl << "Chose the node that you want to alter (use the first number): ";
	int node = this->intHandler(nodes.size());

	this->map->solution(this->map->getPontos()[node]);
	std::vector<Node*> nodeSolucao = this->map->getSolucao();
	cout << "The solution is the following" << endl;
	for (unsigned int i = 0; i != nodeSolucao.size(); i++) {
		cout << i << ": (Id)" << nodeSolucao[i]->getId() << " , (X)" << nodeSolucao[i]->getX() << " , (Y)" << nodeSolucao[i]->getY() << " , (Type)";
		switch (nodeSolucao[i]->getTipo()) {
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
	cout << endl << "Write anything to go back to main menu: ";
	string cenas = this->srtingHandler();
}

