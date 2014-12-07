#pragma once
#include "stdafx.h"
template<class graph_type>
class Graph_SearchDFS
{
private:
	//to aid legibility
	enum { visited, unvisited, no_parentassigned };

	//create typedefs for the edge and node types used by the graph
	typedef typename graph_type::EdgeType Edge;
	typedef typename graph_type::NodeType Node;

private:

	//a reference to the graph to be seardched
	const graph_type& m_Graph;

	//this records the indexes of all the nodes that aare visited as the
	//search progresses
	std::vector<int> m_Visited;

	//this holds the route taken to the target
	std::vector<int> m_Route;

	//the source and the target node indices
	int m_iSource,
		m_iTarget;

	//true if the path to the target has been found
	bool m_bFound;

	//this method performs the DFS search
	bool Search();

public:
	Graph_SearchDFS(const graph_type& graph,
		int source,
		int target = -1) :
		m_Graph{ graph },
		m_iSource{ source },
		m_iTarget{ target },
		m_bFound{ false },
		m_Visited{ m_Graph.NumNodes(), unvisited },
		m_Route{ m_Graph.NumNodes(), no_paretn_assigned }
	{
		m_bFound = Search();
	}

	//returns true if the target node has been located
	bool Found() const { return m_bFound; }

	//returns a vector of node indexes that comprise the shortest path
	//from the source to the target
	std::list<int> GetPathToTarget()const;

	virtual ~Graph_SearchDFS();
};

