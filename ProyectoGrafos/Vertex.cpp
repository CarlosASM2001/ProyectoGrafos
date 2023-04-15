#include "Vertex.h"
#include <iostream>
#include <list>
#include <vector>
#include "Edge.h"

using namespace std;

//Constructors
Vertex::Vertex() {
	state_id = 0;
	state_name = "";
}

Vertex::Vertex(int id, string sname) {
	state_id = id;
	state_name = sname;
}

//Methods
void Vertex::printEdgeList() {
	for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
		cout << "\t\tFrom: " << state_name << " -> To Node ID: " << it->getDestinationVertexID() << " (W: " << it->getWeight() << ")" << endl;
	}

	if (edgeList.empty()) {
		cout << "\t\tNo Edges!" << endl;
	}
	cout << endl;
}


void Vertex::checkAllEdges(set < int >& s) {
	for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
		s.insert(it->getDestinationVertexID());
	}
}


void Vertex::updateVertexName(string sname) {
	state_name = sname;
	cout << "Vertex Name Updated Successfully";
}

bool Vertex::edgeListIsEmpty() {
	return edgeList.empty();
}


//Getters
int Vertex::getStateID() { return state_id; }

string Vertex::getStateName() { return state_name; }

list < Edge > Vertex::getEdgeList() { return edgeList; }

//Setters
void Vertex::setID(int id) { state_id = id; }

void Vertex::setStateName(string sname) { state_name = sname; }
