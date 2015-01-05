#include "IGameEntity.h"
#include "RabbitStateFlee.h"
#include "RabbitStateFactory.h"
#include <iostream>

using namespace Tmpl8;

RabbitStateFlee::RabbitStateFlee()
{
	std::cout << "The Rabbit says: Oh shit!!!\n\n";
	m_eState = FLEE;
}


RabbitStateFlee::~RabbitStateFlee()
{
}

void RabbitStateFlee::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (self->getCenter() - other->getCenter());
	float distance = newHeading.Length();
	if (distance > RDANGERRANGE * 4)
	{
		self->setState(RabbitStateFactory::getInstance().createWanderState());
	}
	else
	{
		newHeading.Normalize();
		
		/*srand(time(nullptr));
		
		int iXMult = 12 - (rand() % 26);
		int iYMult = 12 - (rand() % 26);

		iXMult += newHeading.x;
		iYMult += newHeading.y;

		newHeading.Set(iXMult, iYMult, 0);*/

		ToriodLogic(self);

		//newHeading.Normalize();

		self->setHeading(newHeading);
		self->setSpeed(FLEESPEED);

		self->Move(0.0f);
	}
}
