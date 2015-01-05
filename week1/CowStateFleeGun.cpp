#include "CowStateFleeGun.h"
#include "CowStateFactory.h"
#include "IGameEntity.h"
#include "template.h"
#include <iostream>

using namespace Tmpl8;

CowStateFleeGun::CowStateFleeGun()
{
	m_eState = FLEEGUN;
	std::cout << "The cow says: Gotta get my piece!\n";
}


CowStateFleeGun::~CowStateFleeGun()
{
}

void CowStateFleeGun::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (self->getCenter() - other->getCenter());
	vector3 gunHeading = (neutral->getCenter() - self->getCenter());
	float flee_distance = newHeading.Length();
	float gun_distance = gunHeading.Length();
	if (gun_distance < 32)
	{
		self->setState(CowStateFactory::getInstance().createIdleState());
	}
	else
	{
		//newHeading += gunHeading;
		newHeading.Normalize();
		gunHeading.Normalize();

		ToriodLogic(self);

		if (flee_distance < gun_distance)
		{
			self->setHeading(newHeading);
		}
		else
		{
			self->setHeading(gunHeading);
		}
		self->setSpeed(FLEESPEED);

		self->Move(0.0f);
	}
}