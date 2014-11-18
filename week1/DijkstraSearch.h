#pragma once

#include <vector>
#include <set>
#include <map>

namespace Tmpl8
{
	class Graph;
	class Vertex;
	class Edge;
	class DijkstraSearch
	{
	public:
		DijkstraSearch(Graph* graph);
		virtual ~DijkstraSearch();

		void Execute(Vertex* source);
		vector<Vertex*>* DijkstraSearch::GetPath(Vertex* target);

	private:
		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;
		std::vector<Vertex*>* m_Neighbours;
		std::set<Vertex*> m_UnsettledNodes;
		std::set<Vertex*> m_SettledNodes;
		std::map<Vertex*, Vertex*> m_Predecessors;
		std::map<Vertex*, int> m_Distance;

		void findMinimalDistances(Vertex* node);
		int getDistance(Vertex* node, Vertex* target);
		std::vector<Vertex*>* getNeighbours(Vertex* node);
		Vertex* getMinimum(std::set<Vertex*> vertices);
		int getShortestDistance(Vertex* destination);

		bool isSettled(Vertex* vertex);
	};
}
