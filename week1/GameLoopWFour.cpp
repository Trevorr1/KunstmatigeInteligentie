#include "GameLoopWFour.h"

using namespace Tmpl8;

GameLoopWFour::GameLoopWFour()
{
	m_Cow = new Cow();
	m_Rabbit = new Rabbit();
}


GameLoopWFour::~GameLoopWFour()
{
	delete m_Cow;
	delete m_Rabbit;
}

void GameLoopWFour::Tick(float dt)
{
	m_Cow->chase(m_Rabbit, dt);
	m_Rabbit->Lookout(m_Cow, dt);
}