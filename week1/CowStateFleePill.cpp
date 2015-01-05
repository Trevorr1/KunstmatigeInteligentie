#include "CowStateFleePill.h"
#include "CowStateFactory.h"
#include "IGameEntity.h"
#include "template.h"
#include <iostream>

using namespace Tmpl8;

CowStateFleePill::CowStateFleePill()
{
	m_eState = FLEEPILL;
	std::cout << "Cow says: Gotta find my drugs...\n";
}


CowStateFleePill::~CowStateFleePill()
{
}

void CowStateFleePill::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (self->getCenter() - other->getCenter());
	vector3 pillHeading = (ally->getCenter() - self->getCenter());
	float flee_distance = newHeading.Length();
	float pill_distance = pillHeading.Length();
	if (pill_distance < 32)
	{
		self->setState(CowStateFactory::getInstance().createInvularableState());
	}
	else
	{
		//newHeading += pillHeading;
		newHeading.Normalize();
		pillHeading.Normalize();

		ToriodLogic(self);

		if (flee_distance < pill_distance)
		{
			self->setHeading(newHeading);
		}
		else
		{
			self->setHeading(pillHeading);
		}
		self->setSpeed(FLEESPEED);

		self->Move(0.0f);
	}
}