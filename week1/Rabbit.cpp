#include "Rabbit.h"
#include "Graph.h"
#include "surface.h"

using namespace Tmpl8;

Rabbit::Rabbit(Graph* graph)
{
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/rabbit-3.png"), 1);
}


Rabbit::~Rabbit()
{
	delete m_Sprite;
}

void Rabbit::Update()
{
	m_Sprite->Draw(150, 100, m_Graph->getSurface());
}

void Rabbit::setRoute(eGameEntity source, eGameEntity target)
{

}

void entityMovedNotification(eGameEntity entity)
{

}
