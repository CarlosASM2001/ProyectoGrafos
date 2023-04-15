#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

void loadGraphData(Graph&);
void executeDijkstra(Graph&);
void executeDelete(Graph&);


//================================================
void loadGraphData(Graph& g) {
	Vertex v1, v2;
	string wordLine;
	char* word;
	bool firstLine = true;
	int idVertex = 0;

	ifstream file("aristas.txt", ios::in);//Open txt

	if (file.fail()) {//If the files returns an error, close the program
		cout << "The file could not be opened" << endl;
		exit(1);
	};

	while (getline(file, wordLine)) {//go through the file line by line and save the values in wordLine

		if (!firstLine) { //Ignore first line of the file
			word = strtok((char*)wordLine.c_str(), " -> ");//traverse the line separating by words separated with the token

			//Set attributes to vertex
			v1.setStateName(word);
			v1.setID(idVertex);
			if (g.addVertex(v1)) idVertex++; //If this vertex already exists, it is not added to the graph, if the method addVertex return true "idVertex" increment 

			word = strtok(NULL, " -> ");//go to the next vertex

			v2.setStateName(word);
			v2.setID(idVertex);
			if (g.addVertex(v2)) idVertex++; //If this vertex already exists, it is not added to the graph 

			word = strtok(NULL, " ");//go to the next word

			//Add Edge to the graph
			g.addEdgeByStateName(v1.getStateName(), v2.getStateName(), atoi(word));

		}
		else {
			firstLine = false;
		}

	};
}

//================================================
void executeDijkstra(Graph& g) {
	string resA, resB;
	bool invalidVertex = false;

	do { //Until enter a valid Vertex
		cout << endl;
		if (invalidVertex) {
			system("cls");
			cout << "\n\t" << "INVALID VERTEX! PLEASE TRY AGAIN" << endl;
		}

		cout << "\t" << "Enter the start node of the path: ";
		getline(cin, resA);

		invalidVertex = !g.checkIfVertexExistByStateName(resA);

		

	} while (invalidVertex);

	system("cls");
	invalidVertex = false;

	do { //Until enter a valid Vertex
		cout << endl;
		if (invalidVertex) {
			system("cls");
			cout << "\n\t" << "INVALID VERTEX! PLEASE TRY AGAIN" << endl;
		}
		
		cout << "\t" << "Enter the end node of the path: ";
		getline(cin, resB);

		invalidVertex = !g.checkIfVertexExistByStateName(resB);

		

	} while (invalidVertex);

	system("cls");
	cout << endl;

	g.dijkstra(resA, resB);
}

void executeDelete(Graph& g) {
	string node;
	bool invalidVertex = false;

	do { //Until enter a valid Vertex
		cout << endl;
		if (invalidVertex) {
			system("cls");
			cout << "\n\t" << "INVALID VERTEX! PLEASE TRY AGAIN" << endl;
		}

		cout << "\t" << "Enter the vertex you want to delete: ";
		getline(cin, node);

		invalidVertex = !g.checkIfVertexExistByStateName(node);

	} while (invalidVertex);

	g.deleteVertexByStateName(node);
}