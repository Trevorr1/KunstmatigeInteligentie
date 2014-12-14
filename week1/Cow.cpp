#include "Cow.h"
#include "Graph.h"
#include "surface.h"

using namespace Tmpl8;

Cow::Cow(Graph* graph)
{
	m_Enum = eGameEntity::eCow;
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
}

Cow::~Cow()
{
	delete m_Sprite;
}

void Cow::Draw()
{
	//m_Sprite->Draw(50, 100, m_Graph->getSurface());
}

void Cow::Update(float dt)
{
	if (m_Path.size() > 1)
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
	}
		//state here?
}

void Cow::setRoute(eGameEntity source, eGameEntity target)
{
	m_Path = m_Graph->getPath(source, target);
}

void Cow::entityMovedNotification(eGameEntity entity)
{
	//state here
}
