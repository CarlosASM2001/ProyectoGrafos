#include "Edge.h"
#include<iostream>
#include <vector>

using namespace std;

Edge::Edge() {}

Edge::Edge(int destVID, int w) {
	DestinationVertexID = destVID;
	weight = w;
}

void Edge::setEdgeValues(int destVID, int w) {
	DestinationVertexID = destVID;
	weight = w;
}

void Edge::setWeight(int w) { weight = w; }

void Edge::setDestinationVertexID(int destVID) { DestinationVertexID = destVID; }

int Edge::getDestinationVertexID() { return DestinationVertexID; }

int Edge::getWeight() { return weight; }