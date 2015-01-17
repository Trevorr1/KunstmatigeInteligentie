#include "Cow.h"
#include "Graph.h"
#include "surface.h"
#include "CowWanderState.h"

using namespace Tmpl8;

Cow::Cow(Graph* graph)
{
	m_Enum = eGameEntity::eCow;
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
	m_CurrentState = new CowWanderState(m_Graph, this);
}

Cow::~Cow()
{
	delete m_Sprite;
}

void Cow::Draw()
{
	if (m_CurrentState->getState() == 1)
		m_Sprite->DrawScaled(m_Position.x, m_Position.y, 16, 16, m_Graph->getSurface());
	else
		m_Sprite->Draw(m_Position.x, m_Position.y, m_Graph->getSurface());
	
}

void Cow::Update(float dt)
{
	m_CurrentState->execute();
	//Debug statements to check path size.
	/*if (m_Path.size() > 1)
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eCow);
	}
	else if (m_Path.size() == 1)
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eCow);
	}*/
}

void Cow::setRoute(eGameEntity source, eGameEntity target)
{
	m_Path = m_Graph->getPath(source, target);
}

void Cow::entityMovedNotification(eGameEntity entity)
{
	
}

void Cow::ResetState()
{
	SetState(new CowWanderState(m_Graph, this));
}
