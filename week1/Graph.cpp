#include "Graph.h"

using namespace std;


Graph::Graph(std::vector<Vertex*>* vertices, std::vector<Edge*>* edges)
{
	m_Vertices = vertices;
	m_Edges = edges;
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

vector<Vertex*>* Graph::getVertices()
{
	return m_Vertices;
}

vector <Edge*>* Graph::getEdges()
{
	return m_Edges;
}
