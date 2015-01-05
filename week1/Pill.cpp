#include "Pill.h"
#include "PillStateFactory.h"

using namespace Tmpl8;
Pill::Pill()
{
	m_Enum = eGameEntity::ePill;
	m_Sprite = new Sprite(new Surface("assets/pill32.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = nullptr;

	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 0.0f;
}

Pill::Pill(eState state)
{
	m_Enum = eGameEntity::ePill;
	m_Sprite = new Sprite(new Surface("assets/pill32.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = PillStateFactory::getInstance().createIdleState();
	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 0.0f;
}


Pill::~Pill()
{
}
