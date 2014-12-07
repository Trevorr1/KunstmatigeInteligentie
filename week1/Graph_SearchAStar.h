#pragma once
#include "stdafx.h"
template<class graph_type, class heuristic>
class Graph_SearchAStar
{
private:

	//creat e typedef for the edge type used by the graph
	typedef typename graph_type::EdgeType Edge;

private:

	const graph_type& m_Graph;

	//indexed into by node. Contains the "real" cumulative cost to that node
	std::vector<double> m_GCosts;

	//indexed into by node. Contains the cost from adding m_GCost[n] to
	//the heuristic cost from n to the target node. This is the vector the
	//iPQ indexes into.
	std::vector<double> m_FCost;

	std::vector<const Edge*> m_ShortestPathTree;
	std::vector<const Edge*> m_SearchFrontier;

	int m_iSource;
	int m_iTarget;

	//the A* search algorithm
	void Search();

public:
	Graph_SearchAStar(graph_type& graph,
		int source,
		int target) : m_Graph{ graph },
			m_ShortestPathTree{ graph.NumNodes() },
			m_SearchFrontier{ graph.NumNodes() },
			m_GCost{ graph.NumNodes(), 0.0 },
			m_FCost{ graph.NumNodes(), 0.0 },
			m_iSource{source},
			m_iTarget{target}
	{
		Search();
	}

	//return the vector of edges that the algorithm has examined
	std::vector<const Edge*> GetSPT()const { return m_ShortestPathTree; }

	//returns a vector of node indexes that comprise the shortest path
	//from the source to the target
	std::list<int> GetPathToTarget()const;

	//returns the total cost to the target
	double GetCostToTarget()const;

	virtual ~Graph_SearchAStar();


};

