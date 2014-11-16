#include "DijkstraSearch.h"
#include <limits>

using namespace Tmpl8;
using namespace std;

DijkstraSearch::DijkstraSearch(Graph* graph)
{
	m_Nodes = graph->getVertices();
	m_Edges = graph->getEdges();
	m_SearchResult = new vector<Vertex*>();

	m_VisitedNodes = new set<Vertex*>();
	m_UnVisitedNodes = new set<Vertex*>();

	for (std::vector<Vertex*>::iterator it = m_Nodes->begin(); it != m_Nodes->end(); it++)
	{
		m_UnVisitedNodes->insert(*it);
	}
}


DijkstraSearch::~DijkstraSearch()
{
}

void DijkstraSearch::Execute(Vertex* source)
{
	m_Distance->insert(pair<Vertex*, int>(source, 0));
	m_UnsettledNodes->insert(source);
	while (m_UnsettledNodes->size > 0)
	{
		Vertex* node = getMinimum(m_UnsettledNodes);
		m_SettledNodes->insert(node);
		m_UnsettledNodes->erase(node);
		findMinimalDistances(node);
	}
}

void DijkstraSearch::findMinimalDistances(Vertex* node)
{
	vector<Vertex*>* adjecentNodes = getNeighbors(node);
	for (std::vector<Vertex*>::iterator it = adjecentNodes->begin(); it != adjecentNodes->end; it++)
	{
		if (getShortesDistance(*it) > getShortesDistance(node) + getDistance(node, *it))
		{
			m_Distance->insert(pair<Vertex*, int>(*it, (getShortesDistance(node) + getDistance(node, *it))));
			m_Predecessors->insert(*it, node);
			m_UnsettledNodes->insert(*it);
		}
	}
}

int DijkstraSearch::getDistance(Vertex* node, Vertex* target)
{
	for (std::vector<Edge*>::iterator it = m_Edges->begin(); it != m_Edges->end(); it++)
	{
		if ((*it)->getSource() == node && (*it)->getDestination() == target)
		{
			return (*it)->getWeight();
		}
	}
}

vector<Vertex*>* DijkstraSearch::getNeighbors(Vertex* node)
{
	vector<Vertex*>* neighbors;
	for (std::vector<Edge*>::iterator it = m_Edges->begin(); it != m_Edges->end(); it++)
	{
		if ((*it)->getSource() == node && !isSettled((*it)->getDestination()))
		{
			neighbors->push_back((*it)->getDestination());
		}
	}
	return neighbors;
}

vector<Vertex*>* DijkstraSearch::getNeighbors2(Vertex* node)
{
	vector<Vertex*>* neighbors;
	for (std::vector<Edge*>::iterator it = m_Edges->begin(); it != m_Edges->end(); it++)
	{
		if ((*it)->getSource() == node && !isSettled((*it)->getDestination()))
		{
			neighbors->push_back((*it)->getDestination());
		}
	}
	return neighbors;
}

Vertex* DijkstraSearch::getMinimum(std::set<Vertex*>* vertexes)
{
	Vertex* minimum = nullptr;
	for (std::set<Vertex*>::iterator it = vertexes->begin(); it != vertexes->end(); it++)
	{
		if (minimum == nullptr)
		{
			minimum = *it;
		}
		else
		{
			if (getShortesDistance(*it) < getShortesDistance(minimum))
			{
				minimum = *it;
			}
		}
	}
	return minimum;
}

void DijkstraSearch::AddVertex(Vertex* vertex)
{
	m_Nodes->push_back(vertex);
	m_UnVisitedNodes->insert(vertex);
}

void DijkstraSearch::DeleteVertex(int index)
{
	if (index < m_Nodes->size() && index >= 0)
	{
		m_Nodes->erase(m_Nodes->begin() + index);
	}
}

void DijkstraSearch::EditVertex(int index, std::string desc)
{
	if (index < m_Nodes->size() && index >= 0)
	{
		m_Nodes->at(index)->setDescription(desc);
	}
}

int DijkstraSearch::getShortesDistance(Vertex* destination)
{
	int d = m_Distance->at(destination);
	if (d != 0)
	{
		return d;
	}
	else
	{
		return std::numeric_limits<int>::max();
	}
}

vector<Vertex*>* DijkstraSearch::GetPath(Vertex* target)
{
	vector<Vertex*>* path;
	Vertex* step = target;
	if (m_Predecessors->at(step) == nullptr)
	{
		return nullptr;
	}
	path->push_back(step);
	while (m_Predecessors->at(step) != nullptr)
	{
		step = m_Predecessors->at(step);
		path->push_back(step);
	}

	std::reverse(path->begin(), path->end());
	return path;
}

void DijkstraSearch::SearchPlayer(Vertex* source)
{
	vector<Vertex*>* adjecentNodes;

	while (m_UnVisitedNodes->size() > 0)
	{
		adjecentNodes = getNeighbors2(source);

		if (adjecentNodes->empty())
			return;

		for (std::vector<Vertex*>::iterator it = adjecentNodes->begin(); it != adjecentNodes->end(); it++)
		{
			/*if (target.getEntity().getEntityType() == EntityType.PLAYER) {
				System.out.println("Player found in vertex: "
					+ target.getName());
				searchResult.add(target);
				unVisitedNodes.remove(target);
			}*/
			m_VisitedNodes->insert(*it);
			SearchPlayer(*it);
		}
	}
}