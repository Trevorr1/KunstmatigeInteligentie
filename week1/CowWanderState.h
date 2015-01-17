#pragma once
#include "IFSMCow.h"
#include "Graph.h"
#include "Cow.h"

namespace Tmpl8
{ 
	class Graph;
	class CowWanderState : public IFSMCow
	{
	public:
		CowWanderState(Graph* graph, IGameEntity* entity);
		virtual ~CowWanderState();
		void execute();
		int getState() { return 1; }
		bool isDone() { return m_Done; }
	private:
		Graph* m_Graph;
		std::list<Vertex*> m_Path;
		IGameEntity* m_Entity;
		bool m_FirstRun;
	};
}

