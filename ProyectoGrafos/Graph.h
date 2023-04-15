#include<iostream>
#include <list>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
	vector < Vertex > vertices;
public:

	void printGraph();

	//Dijkstra methods
	void dijkstra(string, string);
	int min_distance(int[], bool[]);

	//Strongly Connected Method
	void checkIsStronglyConnected();

	//Vertex Operations
	bool checkIfVertexExistByID(int);
	bool checkIfVertexExistByStateName(string);
	bool addVertex(Vertex);
	void deleteVertexByID(int);
	void deleteVertexByStateName(string);

	Vertex getVertexByID(int);
	Vertex  getVertexByStateName(string);
	void getAllNeighborsByID(int);

	//Edge Operations
	bool checkIfEdgeExistByID(int, int);
	bool checkIfEdgeExistByStateName(string, string);

	void addEdgeByID(int, int, int);
	void addEdgeByStateName(string, string, int);
	void deleteEdgeByID(int, int);
};

#endif

