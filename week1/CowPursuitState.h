#pragma once
#include "IFSMCow.h"
#include "Cow.h"

namespace Tmpl8
{
	class Graph;
	class CowPursuitState : public IFSMCow
	{
	public:
		CowPursuitState(Graph* graph, IGameEntity* entity);
		virtual ~CowPursuitState();
		void execute();
		int getState() { return 2; }
	private:
		Graph* m_Graph;
		std::list<Vertex*> m_Path;
		IGameEntity* m_Entity;
		bool m_FirstRun;
	};
}

