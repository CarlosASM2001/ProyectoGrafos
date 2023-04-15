#include<iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
	int DestinationVertexID;
	int weight;

	Edge();
	Edge(int destVID, int w);

	//Setters
	void setEdgeValues(int, int);
	void setWeight(int w);
	void setDestinationVertexID(int);

	//Getters
	int getDestinationVertexID();
	int getWeight();
};

#endif

