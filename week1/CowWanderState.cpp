#include "CowWanderState.h"
#include "Graph.h"

using namespace Tmpl8;

CowWanderState::CowWanderState(Graph* graph)
{
	m_Graph = graph;
	m_StateID = 1;
}

CowWanderState::~CowWanderState()
{
}

void CowWanderState::execute()
{
	if (m_Path.size() == 0)
	{
		int index = rand() % m_Graph->getVertices()->size();
		Vertex* next = m_Graph->getVertices()->at(index);
		Vertex* cow = m_Graph->m_LookUpBook.at(eCow);

		m_Path = m_Graph->ComputeAStarPath(cow, next);
	}
	else
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eCow);
	}

	printf("Cow is in wandering state!\n");
}
