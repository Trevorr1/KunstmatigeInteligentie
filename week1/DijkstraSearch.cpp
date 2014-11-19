#include "DijkstraSearch.h"
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

using namespace Tmpl8;
using namespace std;


DijkstraSearch::DijkstraSearch(Graph* graph)
{
	m_Vertices = graph->getVertices();
	m_Edges = graph->getEdges();
	m_Neighbours = new vector<Vertex*>();
}


DijkstraSearch::~DijkstraSearch()
{
	delete m_Neighbours;
	//iterate maybe
}

void DijkstraSearch::Execute(Vertex* source)
{
	m_Distance.insert(std::pair<Vertex*, int>(source, 0));
	m_UnsettledNodes.insert(source);
	set<Vertex*>::iterator it;

	while (m_UnsettledNodes.size() > 0)
	{
		Vertex* node = getMinimum(m_UnsettledNodes);
		m_SettledNodes.insert(node);
		//it = m_SettledNodes.find(node);
		m_UnsettledNodes.erase(node);
		findMinimalDistances(node);

		printf("unsettlednode size: %d\n", m_UnsettledNodes.size());
	}
}

void DijkstraSearch::findMinimalDistances(Vertex* node)
{
	vector<Vertex*>* adjacentNodes = getNeighbours(node);
	for (Vertex* target : *adjacentNodes) 
	{
		if (getShortestDistance(target) > getShortestDistance(node) + getDistance(node, target)) 
		{
			m_Distance.insert(std::pair<Vertex*, int>(target, getShortestDistance(node) + getDistance(node, target))); //this might be wrong, try building trev
			m_Predecessors.insert(std::pair<Vertex*,Vertex*>(target, node));
			m_UnsettledNodes.insert(target);
		}
	}
}

int DijkstraSearch::getDistance(Vertex* node, Vertex* target)
{
	for (Edge* edge : *m_Edges) 
	{
		if (edge->getSource() == node && edge->getDestination() == target) 
		{
			return edge->getWeight();
		}
	}

	return -1;
	//maybe throw exception here??
}

vector<Vertex*>* DijkstraSearch::getNeighbours(Vertex* node)
{
	//List<Vertex> neighbors = new ArrayList<Vertex>();
	for (Edge* edge : *m_Edges) {
		if (edge->getSource() == node && !isSettled(edge->getDestination())) {
			m_Neighbours->push_back(edge->getDestination());
		}
	}
	return m_Neighbours;
}

Vertex* DijkstraSearch::getMinimum(set<Vertex*> vertices)
{
	Vertex* minimum = nullptr;
	for (Vertex* vertex : vertices) 
	{
		if (minimum == nullptr) 
			minimum = vertex;
		else 
		{
			if (getShortestDistance(vertex) < getShortestDistance(minimum)) 
				minimum = vertex;
		}
	}
	return minimum;
}

int DijkstraSearch::getShortestDistance(Vertex* destination)
{
	std::map<Vertex*, int>::iterator it = m_Distance.find(destination);
	if (it != m_Distance.end())
	{
		return m_Distance.at(destination); //vang af

		/*if (d == NULL)
			return INT_MAX;
		else
			return d;*/
	}
	else
		return INT_MAX;
}

vector<Vertex*>* DijkstraSearch::GetPath(Vertex* target)
{
	vector<Vertex*>* path = nullptr;
	Vertex* step = target;
	if (m_Predecessors.at(step) == nullptr)
	{
		return nullptr;
	}
	path->push_back(step);
	while (m_Predecessors.at(step) != nullptr)
	{
		step = m_Predecessors.at(step);
		path->push_back(step);
	}

	std::reverse(path->begin(), path->end());
	return path;
}

bool DijkstraSearch::isSettled(Vertex* vertex)
{
	set<Vertex*>::iterator it;
	it = m_SettledNodes.find(vertex);

	if (it != m_SettledNodes.end())
		return true;
	else
		return false;
}
