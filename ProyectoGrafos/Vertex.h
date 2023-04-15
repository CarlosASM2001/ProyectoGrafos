#include<iostream>
#include <list>
#include <set>
#include "Edge.h"

using namespace std;

#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
public:
	int state_id;
	string state_name;
	list <Edge> edgeList;

	Vertex();
	Vertex(int id, string sname);

	void printEdgeList();
	void checkAllEdges(set < int >& s);
	void updateVertexName(string);
	bool edgeListIsEmpty();

	//Getters
	int getStateID();
	string getStateName();
	list < Edge > getEdgeList();

	//Setters
	void setID(int);
	void setStateName(string);
};

#endif