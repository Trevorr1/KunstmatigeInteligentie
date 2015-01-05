#include "Cow.h"
#include "Graph.h"
#include "surface.h"
#include "CowStateFactory.h"

using namespace Tmpl8;

Cow::Cow()
{
	m_Enum = eGameEntity::eCow;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = CowStateFactory::getInstance().createPursuitState();

	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 1.0f;
}

Cow::Cow(eState state)
{
	m_Enum = eGameEntity::eCow;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = CowStateFactory::getInstance().createState(state);

	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 1.0f;
}

Cow::Cow(Graph* graph)
{
	m_Enum = eGameEntity::eCow;
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
}

Cow::~Cow()
{
	delete m_Sprite;
	delete m_State;
}


void Cow::Update(float dt)
{
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
		//state here?
}


void Cow::chase(IGameEntity* entity, float dt)
{
	m_State->Run(this, entity, nullptr, nullptr);
	Draw();
}



void Cow::setRoute(eGameEntity source, eGameEntity target)
{
	m_Path = m_Graph->getPath(source, target);
}

void Cow::entityMovedNotification(eGameEntity entity)
{
	//state here
}
