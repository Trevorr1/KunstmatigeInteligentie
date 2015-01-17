#include "CowPursuitState.h"
#include "Graph.h"

using namespace Tmpl8;

CowPursuitState::CowPursuitState(Graph* graph, IGameEntity* entity)
{
	m_Graph = graph;
	m_StateID = 2;
	m_Entity = entity;
	m_FirstRun = true;
}


CowPursuitState::~CowPursuitState()
{
}

void CowPursuitState::execute()
{
	if (m_Path.size() == 0 && m_FirstRun)
	{
		m_Path = m_Graph->getPath(eCow, eRabbit);
		m_FirstRun = false;
	}
	else if (m_Path.size() > 0)
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eCow);
	}
	else if (m_Path.size() == 0 && m_FirstRun == false)
	{
		m_Graph->ShuffleHare();
		m_Entity->ResetState();
	}

	printf("Cow is in pursuit state!\n");
}
