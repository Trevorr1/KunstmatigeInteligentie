#include "Weapon.h"
#include "WeaponStateFactory.h"

using namespace Tmpl8;
Weapon::Weapon()
{
	m_Enum = eGameEntity::eCow;
	m_Sprite = new Sprite(new Surface("assets/gun-metal32.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = nullptr;

	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 0.0f;
}

Weapon::Weapon(eState state)
{
	m_Enum = eGameEntity::eCow;
	m_Sprite = new Sprite(new Surface("assets/gun-metal32.png"), 1);
	m_Surface = DrawManager::getInstance().getScreen();

	m_State = WeaponStateFactory::getInstance().createState(state);

	m_Position = vector3();
	m_Heading = vector3();
	m_Speed = 0.0f;
}


Weapon::~Weapon()
{
	delete m_Sprite;
	delete m_State;
}
