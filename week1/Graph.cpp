#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "surface.h"
#include "template.h"

#include <queue>
#include <iostream>

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

	location[0] = new Vertex("V0", 0, vector3(50.0f, 240.0f, 0.0f));
	location[1] = new Vertex("V1", 1, vector3(100.0f, 140.0f, 0.0f));
	location[2] = new Vertex("V2", 2, vector3(110.0f, 340.0f, 0.0f));
	location[3] = new Vertex("V3", 3, vector3(200.0f, 240.0f, 0.0f));
	location[4] = new Vertex("V4", 4, vector3(300.0f, 340.0f, 0.0f));
	location[5] = new Vertex("V5", 5, vector3(350.0f, 140.0f, 0.0f));
	location[6] = new Vertex("V6", 6, vector3(350.0f, 240.0f, 0.0f));
	location[7] = new Vertex("V7", 7, vector3(450.0f, 330.0f, 0.0f));
	location[8] = new Vertex("V8", 8, vector3(500.0f, 220.0f, 0.0f));

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
	addEdge(4, 7, 100);
	addEdge(5, 6, 84);
	addEdge(5, 8, 502);
	addEdge(6, 7, 224);
	addEdge(7, 8, 167);

	std::vector<std::string> vertex_names;

	vertex_names.push_back("Harrisburg");  
	vertex_names.push_back("Baltimore");   
	vertex_names.push_back("Washington");  
	vertex_names.push_back("Philadelphia");
	vertex_names.push_back("Binghamton");  
	vertex_names.push_back("Allentown");   
	vertex_names.push_back("New York"); 
	m_AdjacencyMap[0].push_back(Neighbour(1, 79));
	m_AdjacencyMap[0].push_back(Neighbour(5, 81));

	m_AdjacencyMap[1].push_back(Neighbour(0, 79));
	m_AdjacencyMap[1].push_back(Neighbour(2, 39));
	m_AdjacencyMap[1].push_back(Neighbour(3, 102));

	m_AdjacencyMap[2].push_back(Neighbour(1, 39));

	m_AdjacencyMap[3].push_back(Neighbour(1, 102));
	m_AdjacencyMap[3].push_back(Neighbour(5, 62));
	m_AdjacencyMap[3].push_back(Neighbour(6, 96));

	m_AdjacencyMap[4].push_back(Neighbour(5, 133));

	m_AdjacencyMap[5].push_back(Neighbour(0, 81));
	m_AdjacencyMap[5].push_back(Neighbour(3, 62));
	m_AdjacencyMap[5].push_back(Neighbour(4, 133));
	m_AdjacencyMap[5].push_back(Neighbour(6, 91));

	m_AdjacencyMap[6].push_back(Neighbour(3, 96));
	m_AdjacencyMap[6].push_back(Neighbour(5, 91));

	ComputePath(0, m_AdjacencyMap, m_MinimumDistance, m_Previous);

	/*for (std::map<int, std::list<Neighbour>>::iterator vertex_iter = m_AdjacencyMap.begin(); vertex_iter != m_AdjacencyMap.end(); vertex_iter++)
	{
		int v = vertex_iter->first;
		std::cout << "Distance to " << vertex_names[v] << ": " << m_MinimumDistance[v] << std::endl;
		std::list<int> path = GetShortestPathTo(0, v, m_Previous);
		std::list<int>::iterator path_iter = path.begin();
		std::cout << "Path: ";
		for (; path_iter != path.end(); path_iter++)
		{
			std::cout << vertex_names[*path_iter] << " ";
		}
		std::cout << std::endl;
	}*/

	std::cout << "Distance from 0 to 4: " << m_MinimumDistance[4] << std::endl;
	std::list<int> path = GetShortestPathTo(0, 6, m_Previous);
	std::cout << "Path : ";
	std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
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

void Graph::ComputePath(int source, std::map<int, std::list<Neighbour>>& adjacencyMap, std::map<int, int>& minDistance, std::map<int, int>& previous)
{
	for (std::map<int, std::list<Neighbour>>::iterator vertex_iter = adjacencyMap.begin(); vertex_iter != adjacencyMap.end(); vertex_iter++)
	{
		int v = vertex_iter->first;
		minDistance[v] = std::numeric_limits<int>::infinity();
	}

	minDistance[source] = 0;

	std::set<std::pair<int, int>, pair_first_less<int, int>> vertex_queue;
	for (std::map<int, std::list<Neighbour>>::iterator vertex_iter = adjacencyMap.begin(); vertex_iter != adjacencyMap.end(); vertex_iter++)
	{
		int v = vertex_iter->first;
		vertex_queue.insert(std::pair<int, int>(minDistance[v], v));
	}

	//previous[source] = source;

	while (!vertex_queue.empty())
	{
		int u = vertex_queue.begin()->second;
		vertex_queue.erase(vertex_queue.begin());

		// Visit each edge exiting u
		for (std::list<Neighbour>::iterator edge_iter = adjacencyMap[u].begin(); edge_iter != adjacencyMap[u].end(); edge_iter++)
		{
			int v = edge_iter->m_Target;
			int  weight = edge_iter->m_Weight;

			//relax the edge(u, v)
			int distance_through_u = minDistance[u] + weight;

			if (minDistance[v] == 0)
			{
				minDistance[v] = distance_through_u;
				previous[v] = u;
				vertex_queue.insert(std::pair<int, int>(distance_through_u, v));
			}
			
			if (distance_through_u < minDistance[v]) 
			{
				//remove v from queue
				vertex_queue.erase(std::pair<int, int>(minDistance[v], v));

				minDistance[v] = distance_through_u;
				previous[v] = u;

				//re - add v to queue
				vertex_queue.insert(std::pair<int, int>(minDistance[v], v));
			}
		}
	}
}

std::list<int> Graph::GetShortestPathTo(int source, int target, std::map<int, int>& previous)
{
	std::list<int> path;
	std::map<int, int>::iterator prev;
	int vertex = target;
	path.push_front(vertex);

	while ((prev = previous.find(vertex)) != previous.end())
	{
		vertex = prev->second;
		path.push_front(vertex);
		if (vertex == source)
			break;
	}
	return path;
}

void Graph::ComputeAStarPath(Vertex* source)
{
}

void Graph::addEdge(short sourceLocNo, short destLocNo, int duration) 
{
	Edge* edge = new Edge(m_Vertices->at(sourceLocNo), m_Vertices->at(destLocNo), sourceLocNo, destLocNo, duration);
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
