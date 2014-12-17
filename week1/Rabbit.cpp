#include "Rabbit.h"
#include "Cow.h"
#include "Graph.h"
#include "surface.h"
#include "RabbitStateFactory.h"

using namespace Tmpl8;

Rabbit::Rabbit()
{
	m_Enum = eGameEntity::eRabbit;
	m_Sprite = new Sprite(new Surface("assets/rabbit-3.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = RabbitStateFactory::getInstance().createWanderState();

	m_Position = vector3(SCRWIDTH/2.0f,SCRHEIGHT/2.0f,0);
	m_Heading = vector3();
	m_Speed = 1.0f;
}

Rabbit::Rabbit(Graph* graph)
{
	m_Enum = eGameEntity::eRabbit;
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/rabbit-3.png"), 1);
}

Rabbit::~Rabbit()
{
	delete m_Sprite;
	delete m_State;
}

void Rabbit::Draw()
{
	m_Sprite->Draw(m_Position.x, m_Position.y, m_Surface);
}

void Rabbit::Update(float dt)
{
	/*if (m_Path.size() > 1){
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eRabbit);
	}
	else if (m_Path.size() == 1)
	{
		Vertex* target = m_Path.front();
		m_Path.pop_front();
		m_Graph->moveGameObject(target, eRabbit);
	}*/

}

void Rabbit::Lookout(IGameEntity* entity, float dt)
{
	m_State->Run(this, entity);
	Draw();
}

void Rabbit::setRoute(eGameEntity source, eGameEntity target)
{
	m_Path = m_Graph->getPath(source, target);
}

void Rabbit::entityMovedNotification(eGameEntity entity)
{
	//state here
}
