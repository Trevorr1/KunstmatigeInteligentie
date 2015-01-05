#include "CowStatePursuit.h"
#include "IGameEntity.h"
#include <iostream>

using namespace Tmpl8;

CowStatePursuit::CowStatePursuit()
{
	m_eState = PURSUIT;
	std::cout << "Cow says: Swiggity swooty I'm coming for that booty! I mean, Mooooo!\n\n";
}


CowStatePursuit::~CowStatePursuit()
{
}

void CowStatePursuit::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (other->getPosition() - self->getPosition());

	newHeading.Normalize();
	self->setSpeed(PURSUITSPEED);
	self->setHeading(newHeading);
	self->Move(0.0f);
}