#include "CowWanderState.h"
#include "CowPursuitState.h"
#include "Graph.h"

using namespace Tmpl8;

CowWanderState::CowWanderState(Graph* graph, IGameEntity* entity)
{
	m_Graph = graph;
	m_StateID = 1;
	m_Entity = entity;
	m_FirstRun = true;
}

CowWanderState::~CowWanderState()
{
}

void CowWanderState::execute()
{
	if (m_Path.size() == 0 && m_FirstRun)
	{
		int index = rand() % m_Graph->getVertices()->size();
		Vertex* next = m_Graph->getVertices()->at(index);
		Vertex* cow = m_Graph->m_LookUpBook.at(eCow);

		m_Path = m_Graph->ComputeAStarPath(cow, next);
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
		m_Entity->SetState(new CowPursuitState(m_Graph, m_Entity));
	}

	printf("Cow is in wandering state!\n");
}
