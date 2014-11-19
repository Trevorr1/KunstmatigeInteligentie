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
	for (unsigned int i = 0; i < 10; i++) 
	{
		string strID = to_string(i);
		location = new Vertex("V" + strID, "V" + strID);
		m_Vertices->push_back(location);
	}

	location = nullptr;

	addEdge(0, 1, 85);
	addEdge(0, 2, 217);
	addEdge(0, 4, 173);
	addEdge(2, 6, 186);
	addEdge(2, 7, 103);
	addEdge(3, 7, 183);
	addEdge(5, 8, 250);
	addEdge(8, 9, 84);
	addEdge(7, 9, 167);
	addEdge(4, 9, 502);
	addEdge(9, 10, 40);
}

void Graph::addEdge(int sourceLocNo, int destLocNo, int duration) 
{
	Edge* edge = new Edge(m_Vertices->at(sourceLocNo), m_Vertices->at(destLocNo), duration);
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
