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
	m_Distance.insert(std::pair<Vertex*,int>(source, 0)); //this might be wrong, try building trev
	m_UnsettledNodes.insert(source);

	set<Vertex*>::iterator it;
	while (m_UnsettledNodes.size() > 0)
	{
		Vertex* node = getMinimum(m_UnsettledNodes);
		m_SettledNodes.insert(node);
		m_UnsettledNodes.insert(node);
		findMinimalDistances(node);
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
			m_Predecessors.insert(target, node);
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
	int d = m_Distance.at(destination);
	if (d == NULL)
		return INT_MAX;
	else
		return d;
}

//@@@@@@@@@@@@@@@@@@@@@@ Trevorr
//TRANSLATE ME TO C++
/////////////////////////////////
//public LinkedList<Vertex> getPath(Vertex target) {
//
//	LinkedList<Vertex> path = new LinkedList<Vertex>();
//	Vertex step = target;
//	// check if a path exists
//	if (predecessors.get(step) == null) { //m_Predessors
//		return null;
//	}
//	path.add(step);
//	while (predecessors.get(step) != null) { //m_Predessors
//		step = predecessors.get(step);
//		path.add(step);
//	}
//	// Put it into the correct order
//	Collections.reverse(path);
//	return path;
//}

bool DijkstraSearch::isSettled(Vertex* vertex)
{
	set<Vertex*>::iterator it = m_SettledNodes.find(vertex);
	if (*it != nullptr)
		return true;
	else
		return false;
}
