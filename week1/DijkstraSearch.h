#pragma once
#include <vector>
#include <map>
#include <set>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

namespace Tmpl8
{
	class DijkstraSearch
	{
	public:
		DijkstraSearch(Graph* graph);
		virtual ~DijkstraSearch();

		void Execute(Vertex* source);
		void AddVertex(Vertex* vertex);
		void DeleteVertex(int index);
		void EditVertex(int index, string desc);
		void SearchPlayer(Vertex* source);

		std::vector<Vertex*>* GetPath(Vertex* target);

		std::vector<Vertex*>* GetDepthFirstSearchResult() { return m_SearchResult; }
		
		
	private:
		std::vector<Vertex*>* m_Nodes;
		std::vector<Edge*>* m_Edges;
		std::vector<Vertex*>* m_SearchResult;
		std::set<Vertex*>* m_SettledNodes, *m_VisitedNodes;
		std::set<Vertex*>* m_UnsettledNodes, *m_UnVisitedNodes;
		std::map<Vertex*, Vertex*>* m_Predecessors;
		std::map<Vertex*, int>* m_Distance;

		void findMinimalDistances(Vertex* Node);
		int getDistance(Vertex* node, Vertex* target);
		int getShortesDistance(Vertex* destination);
		std::vector<Vertex*>* getNeighbors(Vertex* node);
		std::vector<Vertex*>* getNeighbors2(Vertex* node);
		Vertex* getMinimum(std::set<Vertex*>* vertexes);

		bool isSettled(Vertex* vertex){ return (std::find(m_SettledNodes->begin(), m_SettledNodes->end(), vertex) != m_SettledNodes->end()); }
		bool isVisited(Vertex* vertex){ return(std::find(m_VisitedNodes->begin(), m_VisitedNodes->end(), vertex) != m_VisitedNodes->end()); }

	};
}
