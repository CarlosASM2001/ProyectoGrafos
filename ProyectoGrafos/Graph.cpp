#include "Graph.h"
#include<iostream>
#include <list>
#include <set>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;


void Graph::printGraph() {
	cout << endl;
	for (int i = 0; i < vertices.size(); i++) {
		Vertex temp;
		temp = vertices.at(i);
		cout << "\tVertex: " << temp.getStateName() << " (ID: " << temp.getStateID() << ")" << endl;
		temp.printEdgeList();
	}
}

//=====================================
//         Vertex Operations
//=====================================


//Check if a Vertext Id exist in the Graph
bool Graph::checkIfVertexExistByID(int vid) {
	bool flag = false;

	for (int i = 0; i < vertices.size(); i++)
		if (vertices.at(i).getStateID() == vid)
			return true;

	return flag;
}


//Check if a Vertext State Name exist in the Graph
bool Graph::checkIfVertexExistByStateName(string vname) {
	bool flag = false;

	for (int i = 0; i < vertices.size(); i++)
		if (vertices.at(i).getStateName() == vname)
			return true;

	return flag;
}


//Add a Vertext to the Graph
bool Graph::addVertex(Vertex newVertex) {

	bool checkId = checkIfVertexExistByID(newVertex.getStateID());
	bool checkName = checkIfVertexExistByStateName(newVertex.getStateName());

	if (checkId || checkName) { //Vertex with this ID or State Name already exist
		return false;
	}
	else {
		vertices.push_back(newVertex);
		//cout << "New Vertex Added Successfully" << endl;
		return true;
	}
}


//Delete a Vertext in the Graph by ID
void Graph::deleteVertexByID(int vid) {
	int vIndex = 0;

	//Find index of vertex into the vector
	for (int i = 0; i < vertices.size(); i++)
		if (vertices.at(i).getStateID() == vid)
			vIndex = i;

	//Erase all edges asociated to that vertex
	for (int i = 0; i < vertices.size(); i++)
		for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
			if (it->getDestinationVertexID() == vid) {
				vertices.at(i).edgeList.erase(it);
				break;
			}

	vertices.erase(vertices.begin() + vIndex);
	cout << "\tVertex Deleted Successfully" << endl;

	//Update Vertex ID to all Edges
	for (int i = 0; i < vertices.size(); i++) {
		for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
			if (it->getDestinationVertexID() > vIndex)
				it->setDestinationVertexID(it->getDestinationVertexID() - 1);

		vertices.at(i).setID(i);
	}


}



//Delete a Vertext in the Graph by State Name
void Graph::deleteVertexByStateName(string vertex) {
	Vertex v = getVertexByStateName(vertex);

	deleteVertexByID(v.getStateID());
}


//Get a specific Vertext in the Graph by ID
Vertex Graph::getVertexByID(int vid) {
	Vertex temp;

	for (int i = 0; i < vertices.size(); i++) {
		temp = vertices.at(i);
		if (temp.getStateID() == vid) {
			return temp;
		}
	}

	return temp;
}


//Get a specific Vertext in the Graph by ID
Vertex Graph::getVertexByStateName(string vname) {
	Vertex temp;

	for (int i = 0; i < vertices.size(); i++) {
		temp = vertices.at(i);
		if (temp.getStateName() == vname) {
			return temp;
		}
	}

	return temp;
}


//Get all Vertex neighbors to a Vertext in the Graph
void Graph::getAllNeighborsByID(int vid) {
	cout << getVertexByID(vid).getStateName() << " (" << getVertexByID(vid).getStateID() << ") --> ";

	for (int i = 0; i < vertices.size(); i++) {
		if (vertices.at(i).getStateID() == vid) {
			cout << "[";
			for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
				cout << it->getDestinationVertexID() << "(" << it->getWeight() << ") --> ";
			}
			cout << "]";
		}
	}
}


//=====================================
//          Edge Operations
//=====================================


//Check if a Edge Id exist in the Graph
bool Graph::checkIfEdgeExistByID(int fromVertex, int toVertex) {

	Vertex v = getVertexByID(fromVertex);
	list < Edge > e;
	e = v.getEdgeList();
	bool flag = false;

	for (auto it = e.begin(); it != e.end(); it++)
		if (it->getDestinationVertexID() == toVertex) {
			flag = true;
			return flag;
			break;
		}

	return flag;
}

//Check if a Vertex Edge by State Name exist in the Graph
bool Graph::checkIfEdgeExistByStateName(string fromVertex, string toVertex) {

	Vertex v1 = getVertexByStateName(fromVertex);
	Vertex v2 = getVertexByStateName(fromVertex);

	return checkIfEdgeExistByID(v1.getStateID(), v2.getStateID());
}


//Add a Edge to the Graph by ID
void Graph::addEdgeByID(int fromVertex, int toVertex, int weight) {

	bool check1 = checkIfVertexExistByID(fromVertex);
	bool check2 = checkIfVertexExistByID(toVertex);

	bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);

	if ((check1 && check2 == true)) { //The vertices are already added to the graph

		if (!check3) { //there is no edge between these two vertices
			for (int i = 0; i < vertices.size(); i++)
				if (vertices.at(i).getStateID() == fromVertex) {
					Edge e(toVertex, weight);
					vertices.at(i).edgeList.push_back(e);
					break;
				}
			//Add Edge Successfully
		}

	}
	else {
		cout << "Invalid Vertex ID entered.";
	}
}


//Add a Edge to the Graph by State Name
void Graph::addEdgeByStateName(string fromVertex, string toVertex, int weight) {
	Vertex v1 = getVertexByStateName(fromVertex);
	Vertex v2 = getVertexByStateName(toVertex);

	addEdgeByID(v1.getStateID(), v2.getStateID(), weight);
}


//Delete a Edge in the Graph
void Graph::deleteEdgeByID(int fromVertex, int toVertex) {
	bool check = checkIfEdgeExistByID(fromVertex, toVertex);

	if (check == true) {
		for (int i = 0; i < vertices.size(); i++)
			if (vertices.at(i).getStateID() == fromVertex)
				for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
					if (it->getDestinationVertexID() == toVertex) {
						vertices.at(i).edgeList.erase(it);
						break;
					}

		cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
	}
}


//Dijkstra Algorithm
void Graph::dijkstra(string fromVertex, string toVertex) {
	Vertex initialV = getVertexByStateName(fromVertex);
	Vertex finalV = getVertexByStateName(toVertex);

	int* dist = new int[vertices.size()];
	int* prev = new int[vertices.size()];
	bool* visited = new bool[vertices.size()];
	int printIndex = 0, verticeVisitado = 0;
	bool imposibleAdvance = false;

	for (int i = 0; i < vertices.size(); i++) { //All vertices stars with the maximum distance from the source vertex
		dist[i] = INT_MAX;
		prev[i] = 0;
		visited[i] = false;
	}

	dist[initialV.getStateID()] = 0;

	do { //Dijkstra Algorithm
		int v = min_distance(dist, visited);

		if (v != -1) { //There are vertices available
			visited[v] = true;

			for (auto it = vertices.at(v).edgeList.begin(); it != vertices.at(v).edgeList.end(); it++)
				if (
					dist[v] + it->getWeight() < dist[it->getDestinationVertexID()]
					) {
					dist[it->getDestinationVertexID()] = dist[v] + it->getWeight();
					prev[it->getDestinationVertexID()] = v;
				}

		}
		else { //It's a source node
			imposibleAdvance = true;
		}

		verticeVisitado++;

	} while (!visited[finalV.getStateID()] && !imposibleAdvance);


	if (imposibleAdvance) { //Impossible to reach that node
		cout << "\t" << "Impossible to reach vertex " << finalV.getStateName() << " from " << initialV.getStateName() << endl;
	}
	else {
		//Print path and Cost
		cout << "\t" << "Cost: " << dist[finalV.getStateID()] << endl;

		printIndex = finalV.getStateID();
		cout << "\n\t" << "PATH: " << endl << "\t";
		do {
			cout << vertices.at(printIndex).getStateName() << " <- ";
			printIndex = prev[printIndex];
		} while (printIndex != initialV.getStateID());
		cout << initialV.getStateName() << endl << endl;
	}
}


//Find the vertex with the smallest associated distance
int Graph::min_distance(int dist[], bool visited[]) {
	int Min = INT_MAX - 1, index = -1;

	for (int i = 0; i < vertices.size(); i++)
		if (dist[i] <= Min && !visited[i]) {
			Min = dist[i];
			index = i;
		}

	return index;
}


//Print if the graph is strongly connected. if it is not, print the nodes of why it is not
void Graph::checkIsStronglyConnected() {
	set<int> s;
	int sourceNodes = 0, sinkNodes = 0;
	bool stronglyConnected = true;

	for (int i = 0; i < vertices.size(); i++) {
		Vertex temp;
		temp = vertices.at(i);
		temp.checkAllEdges(s);

		if (temp.getEdgeList().empty()) {
			sinkNodes++;
			stronglyConnected = false;
		};
	};

	if (!stronglyConnected) {
		cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n\t| Sink nodes found:       |\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		for (int i = 0; i < vertices.size(); i++) {
			Vertex temp = vertices.at(i);

			if (temp.getEdgeList().empty()) {
				cout << "\t Vertex: " << temp.getStateName() << " (ID: " << temp.getStateID() << ")" << endl;
			};
		};
	}

	stronglyConnected = (s.size() == vertices.size()) ? stronglyConnected : false;

	if (s.size() != vertices.size()) {
		cout << "\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n\t| Source Nodes found       |\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		for (int i = 0; i < vertices.size(); i++) {
			Vertex temp = vertices.at(i);
			int num = 0;
			for (auto it = s.begin(); it != s.end(); it++) {
				if (*it == temp.getStateID()) {
					num++;
				};
			};

			if (num == 0) {
				cout << "\t Vertex: " << temp.getStateName() << " (ID: " << temp.getStateID() << ")" << endl;
			}
		};
		cout << "\n\t=========================================" << endl;
	};

	if (!stronglyConnected) {
		sourceNodes = vertices.size() - s.size();
		cout << "\n\tTotal number of source nodes: " << sourceNodes << endl;
		cout << "\tTotal number of sink nodes: " << sinkNodes << endl << endl;
		cout << "\n\t========================================" << endl;
		cout << "\t|| The graph is not strongly connected ||";
		cout << "\n\t========================================" << endl << endl;
	}
	else {
		cout << "\n\t=====================================" << endl;
		cout << "\t|| The graph is strongly connected ||";
		cout << "\n\t=====================================" << endl << endl;
	};

}
