#include "IGameEntity.h"
#include "RabbitStateWander.h"
#include "RabbitStateFactory.h" 
#include <iostream>

using namespace Tmpl8;

RabbitStateWander::RabbitStateWander()
{
	std::cout << "The Rabbit says: I am chilling.\n\n";
	m_eState = WANDER;
	srand(time(NULL));
}


RabbitStateWander::~RabbitStateWander()
{
}


void RabbitStateWander::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	float distance = (self->getCenter() - other->getCenter()).Length();
	if (distance < RDANGERRANGE)
	{
		self->setState(RabbitStateFactory::getInstance().createFleeState());
	}
	else
	{

		int iX = 13 - (rand() % 25);
		int iY = 13 - (rand() % 25);

		vector3 newHeading = vector3((float)iX, (float)iY, 0);

		ToriodLogic(self);

		newHeading.Normalize();

		self->setHeading(newHeading);
		self->setSpeed(WANDERSPEED);

		self->Move(0.0f);
	}
}
