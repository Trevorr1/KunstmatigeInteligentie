#include "Graph_SearchDFS.h"

template<class graph_type>
bool Graph_SearchDFS<graph_type>::Search()
{
	//create a std stack of pointers to edges
	std::stack<const Edge*> stack;

	//create a dummy edge and put on the stack
	Edge Dummy(m_iSource, m_iSource, 0);

	stack.push(&Dummy);

	//while there are edges on the stack keep searching
	while (!stack.empty())
	{
		//grab the next edge
		const Edge* Next = stack.top();

		//remove the edge from the stack
		stack.pop();

		//make a note of the parent of the node this edge points to
		m_Route[Next->To()] = Next->From();

		//and mark it visited
		m_Visited[Next->To()] = visited;

		//if the target has been found the method can return success
		if (Next->To() == m_iTarget)
		{
			return true;
		}

		//push the edges leading from the node this edge points to onto
		//the stack (provided the edge does not point to a previously
		//visited nod)
		graph_type::ConstEdgeIterator ConstEdgeItr(m_Graph, Next->To());

		for (const Edge* pE = ConstEdgeItr.begin();
			!ConstEdgeItr.end();
			pE = ConstEdgeItr.next())
		{
			if (m_Visited[pE->To()] == unvisited)
			{
				stack.push(pE);
			}
		}
	}//while

	//no path to target
	return false;
}

