#pragma once
#include "IFSMCow.h"

namespace Tmpl8
{
	class Graph;
	class CowPursuitState : public IFSMCow
	{
	public:
		CowPursuitState(Graph* graph);
		virtual ~CowPursuitState();
		void execute();
		int getState() { return 2; }
	private:
		Graph* m_Graph;
		std::list<Vertex*> m_Path;
	};
}

