#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

using namespace Tmpl8;
using namespace std;

Graph::Graph()
{
	m_Vertices = new vector<Vertex*>();
	m_Edges = new vector<Edge*>();
}


Graph::~Graph()
{
	for (vector<Vertex*>::iterator it = m_Vertices->begin(); it != m_Vertices->end(); it++)
	{
		delete (*it);
	}

	delete m_Vertices;

	for (vector<Edge*>::iterator it = m_Edges->begin(); it != m_Edges->end(); it++)
	{
		delete (*it);
	}

	delete m_Edges;
}

void Graph::init()
{
	Vertex* location = nullptr;
	for (unsigned int i = 0; i < 11; i++) 
	{
		int id = i;
		string strID = to_string(i);
		location = new Vertex("Node_" + strID, "Node_" + strID, id);
		m_Vertices->push_back(location);
	}
	location = nullptr;

	addEdge(0, 1, 85, "Edge_0");
	addEdge(0, 2, 217, "Edge_1");
	addEdge(0, 4, 173, "Edge_2");
	addEdge(2, 6, 186, "Edge_3");
	addEdge(2, 7, 103, "Edge_4");
	addEdge(3, 7, 183, "Edge_5");
	addEdge(5, 8, 250, "Edge_6");
	addEdge(8, 9, 84, "Edge_7");
	addEdge(7, 9, 167, "Edge_8");
	addEdge(4, 9, 502, "Edge_9");
	addEdge(9, 10, 40, "Edge_10");
	addEdge(1, 10, 600, "Edge_11");
}

void Graph::addEdge(int sourceLocNo, int destLocNo, int duration, string laneId) 
{
	Edge* edge = new Edge(m_Vertices->at(sourceLocNo), m_Vertices->at(destLocNo), duration, laneId);
	m_Edges->push_back(edge);
	edge = nullptr;
}

vector<Vertex*>* Graph::getVertices()
{
	return m_Vertices;
}

vector <Edge*>* Graph::getEdges()
{
	return m_Edges;
}
