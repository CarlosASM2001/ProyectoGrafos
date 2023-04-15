#include <iostream>
#include "Graph.h"
#include "helpers.h"

using namespace std;

void menu(Graph&);

/*===================================================================
							Main Screen
//====================================================================*/
void menu(Graph& g) {
	loadGraphData(g);

	int option;
	do {
		system("cls");

		cout <<
			"\t     _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|__                                               __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|                  Options Menu:                |___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|__                 ----------------              __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|                                               |___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|__  1. Imprimir Grafo                            __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|  2. Verificar si el grafo es fuertemente conexo  |___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|__  3. Eliminar Vertice                          __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|  4. Ruta minima entre dos Vertices            |___|___|___|___|___|__\n" <<
			"\t     _|___|___|___|___|___|__  5. Salir                                     __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|                                               ___|___|___|___|___|___\n" <<
			"\t     _|___|___|___|___|___|__                                               __|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__|___|___|___|___|___|___\n" <<
			"\t     _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n" <<
			"\t     ___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__|___|___|___|___|___|___\n" <<
			"\t     _|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n" <<
			"\n\t      Enter an option: ";

		cin >> option;
		fflush(stdin);

		switch (option) {
		case 1: system("cls");
			g.printGraph();
			system("pause");
			break;

		case 2: system("cls");
			g.checkIsStronglyConnected();
			system("pause");
			break;

		case 3: system("cls");
			executeDelete(g); //helpers.h
			system("pause");
			break;

		case 4: system("cls");
			executeDijkstra(g); //helpers.h
			system("pause");
			break;

		default: break;
		};
	} while (option != 5);
};