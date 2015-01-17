#pragma once
#include "IFSMCow.h"
#include "Graph.h"

namespace Tmpl8
{ 
	class Graph;
	class CowWanderState : public IFSMCow
	{
	public:
		CowWanderState(Graph* graph);
		virtual ~CowWanderState();
		void execute();
		int getState() { return 1; }
	private:
		Graph* m_Graph;
		std::list<Vertex*> m_Path;
	};
}

