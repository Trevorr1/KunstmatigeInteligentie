#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "surface.h"
#include "template.h"

using namespace Tmpl8;
using namespace std;

Graph::Graph(Surface* aTarget)
{
	m_Vertices = new vector<Vertex*>();
	m_Edges = new vector<Edge*>();
	m_Target = aTarget;
}


Graph::~Graph()
{	
	m_Edges->erase(m_Edges->begin(), m_Edges->end());

	delete m_Edges;

	m_Vertices->erase(m_Vertices->begin(), m_Vertices->end());

	delete m_Vertices;
}

void Graph::init()
{
	Vertex* location[9] = { nullptr };

	location[0] = new Vertex("V1", "V1", vector3(50.0f, 240.0f, 0.0f));
	location[1] = new Vertex("V2", "V2", vector3(100.0f, 140.0f, 0.0f));
	location[2] = new Vertex("V3", "V3", vector3(110.0f, 340.0f, 0.0f));
	location[3] = new Vertex("V4", "V4", vector3(200.0f, 240.0f, 0.0f));
	location[4] = new Vertex("V5", "V5", vector3(300.0f, 340.0f, 0.0f));
	location[5] = new Vertex("V6", "V6", vector3(350.0f, 140.0f, 0.0f));
	location[6] = new Vertex("V7", "V7", vector3(350.0f, 240.0f, 0.0f));
	location[7] = new Vertex("V8", "V8", vector3(450.0f, 330.0f, 0.0f));
	location[8] = new Vertex("V9", "V9", vector3(500.0f, 220.0f, 0.0f));

	for (int i = 0; i < 9; i++)
	{
		m_Vertices->push_back(location[i]);
	}

	addEdge(0, 1, 85);
	addEdge(0, 2, 217);
	addEdge(1, 3, 173);
	addEdge(1, 5, 186);
	addEdge(2, 3, 103);
	addEdge(2, 4, 183);
	addEdge(3, 6, 250);
	addEdge(4, 6, 150);
	addEdge(5, 6, 84);
	addEdge(4, 7, 100);
	addEdge(6, 7, 224);
	addEdge(7, 8, 167);
	addEdge(5, 8, 502);
}

void Graph::Draw()
{
	for (int i = 0; i < m_Edges->size(); i++)
	{
		m_Target->Line(m_Edges->at(i)->getSource()->getPosition().x + 12, m_Edges->at(i)->getSource()->getPosition().y + 12,
			m_Edges->at(i)->getDestination()->getPosition().x + 12, m_Edges->at(i)->getDestination()->getPosition().y + 12, 0x0000ff);
	}

	for (int i = 0; i < m_Vertices->size(); i++)
	{
		m_Target->Bar(m_Vertices->at(i)->getPosition().x, m_Vertices->at(i)->getPosition().y,
			m_Vertices->at(i)->getPosition().x + 25, m_Vertices->at(i)->getPosition().y + 25, 0xff0000);
	}
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
