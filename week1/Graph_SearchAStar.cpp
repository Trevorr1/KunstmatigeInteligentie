#include "Graph_SearchAStar.h"
#include <queue>

template<class graph_type, class heuristic>
void Graph_SearchAStar<graph_type, heuristic>::Search()
{
	//creat an indexed priority queue of nodes. The queue will give priority
	//to nodes with low F costs. (F=G+H)
	std::priority_queue<double> pq(m_FCost, m_Graph.NumNodes());

	//put the source node on the queue
	pq.insert(m_iSource);

	//while the queue is not empty
	while (!pq.empty())
	{
		//get lowest cosst node from the queue
		int NextClosestNode = pq.pop();

		//move this node from the frontier to spanning tree
		m_ShortestPathTree[NextClosestNode] = m_SearchFrontier[NextClosestNode];

		//if the target has been found exit
		if (NextClosestNode == m_iTarget) return;

		//now to test all the edges attached to this node
		graph_type::ConstEdgeIterator ConstEdgeItr(m_Graph, NextClosestNode);

		for (const Edge* pE = ConstEdgeItr.begin();
			!ConstEdgeItr.end();
			pE = ConstEdgeItr.next())
		{
			//calculate the heuristic cost from this node to the target (H)
			double HCost = heuristic::Calculate(m_Graph, m_iTarget, pE->To());

			//calculate the "real" cost to this node from the source (G)
			double GCost = m_GCosts[NextClosestNode] + pE->Cost();

			//if the node has not been added to the frontier, add it and update
			//the G and F costs
			if (m_SearchFrontier[pE->To()] == NULL)
			{
				m_FCosts[pE->To()] = GCost + HCost;
				m_GCosts[pE->To()] = GCost;

				pq.ChangePriority(pE->To());

				m_SearchFrontier[pE->To()] = pE;
			}
		}
	}
}
