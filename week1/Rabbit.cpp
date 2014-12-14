#include "Rabbit.h"
#include "Graph.h"
#include "surface.h"

using namespace Tmpl8;

Rabbit::Rabbit(Graph* graph)
{
	m_Enum = eGameEntity::eRabbit;
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/rabbit-3.png"), 1);
}

Rabbit::~Rabbit()
{
	delete m_Sprite;
}

void Rabbit::Draw()
{
	//m_Sprite->Draw(150, 100, m_Graph->getSurface());
}

void Rabbit::Update(float dt)
{
	if (m_Path.size() > 1){
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eRabbit);
	}
	else if (m_Path.size() == 1)
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eRabbit);
	}
}

void Rabbit::setRoute(eGameEntity source, eGameEntity target)
{
	m_Path = m_Graph->getPath(source, target);
}

void Rabbit::entityMovedNotification(eGameEntity entity)
{
	//state here
}
