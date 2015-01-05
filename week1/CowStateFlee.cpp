#include "CowStateFlee.h"
#include "CowStateFactory.h"
#include "IGameEntity.h"
#include "template.h"
#include <iostream>

using namespace Tmpl8;

CowStateFlee::CowStateFlee()
{
	m_eState = FLEE;
	std::cout << "Cow says: OMG OMG OMG MOOO!!!\n";
}


CowStateFlee::~CowStateFlee()
{
}

void CowStateFlee::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (self->getCenter() - other->getCenter());
	float distance = newHeading.Length();
	newHeading.Normalize();

	std::vector<int> odds = m_Options;
	if (distance > CDANGERRANGE * 2)
	{
		self->setState(CowStateFactory::getInstance().createWanderState());
		self->CurrentState()->PushOptions(odds);
	}
	else
	{
		ToriodLogic(self);
		newHeading += self->getHeading();
		newHeading.Normalize();
		self->setHeading(newHeading);
		self->setSpeed(FLEESPEED);

		self->Move(0.0f);
	}
}
