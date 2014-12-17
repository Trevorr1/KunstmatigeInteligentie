#include "RabbitStateFlee.h"
#include "RabbitStateFactory.h"
#include <iostream>

using namespace Tmpl8;

RabbitStateFlee::RabbitStateFlee()
{
	std::cout << "The Rabbit says: Oh shit!!!\n\n";
}


RabbitStateFlee::~RabbitStateFlee()
{
}

void RabbitStateFlee::Run(IGameEntity* entity, IGameEntity* other)
{
	float distance = (entity->getPosition() - other->getPosition()).Length();
	if (distance > DANGERRANGE * 4)
	{
		entity->setState(RabbitStateFactory::getInstance().createWanderState());
	}
	else
	{
		vector3 newHeading = (entity->getPosition() - other->getPosition());
		newHeading.Normalize();
		
		srand(time(nullptr));
		
		int iXMult = 12 - (rand() % 26);
		int iYMult = 12 - (rand() % 26);

		iXMult += newHeading.x;
		iYMult += newHeading.y;

		newHeading.Set(iXMult, iYMult, 0);

		//stay on the screen pls
		if (entity->getPosition().y + 32 > SCRHEIGHT && newHeading.y > 0) 
		{
			newHeading.y *= -1;
		}
		if (entity->getPosition().y < 0 && newHeading.y < 0)
		{
			newHeading.y *= -1;
		}
		if (entity->getPosition().x + 32 > SCRWIDTH && newHeading.x > 0) 
		{
			newHeading.x *= -1;
		}
		if (entity->getPosition().x < 0 && newHeading.x < 0)
		{
			newHeading.x *= -1;
		}

		newHeading.Normalize();

		entity->setHeading(newHeading);
		entity->setSpeed(FLEESPEED);

		entity->Move(0.0f);
	}
}
