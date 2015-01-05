#include "RabbitStateWander.h"
#include "RabbitStateFactory.h" 
#include <iostream>

using namespace Tmpl8;

RabbitStateWander::RabbitStateWander()
{
	std::cout << "The Rabbit says: I am chilling.\n\n";
}


RabbitStateWander::~RabbitStateWander()
{
}


void RabbitStateWander::Run(IGameEntity* entity, IGameEntity* other)
{
	float distance = (entity->getPosition() - other->getPosition()).Length();
	if (distance < DANGERRANGE)
	{
		entity->setState(RabbitStateFactory::getInstance().createFleeState());
	}
	else
	{
		srand(time(nullptr));

		int iX = 13 - (rand() % 25);
		int iY = 13 - (rand() % 25);

		vector3 newHeading = vector3((float)iX, (float)iY, 0);

		//stay on the screen pls
		if (entity->getPosition().y + 32> SCRHEIGHT && newHeading.y > 0)
		{
			newHeading.y *= -1;
		}
		if (entity->getPosition().y < 0 && newHeading.y < 0)
		{
			newHeading.y *= -1;
		}
		if (entity->getPosition().x + 32> SCRWIDTH && newHeading.x > 0)
		{
			newHeading.x *= -1;
		}
		if (entity->getPosition().x < 0 && newHeading.x < 0)
		{
			newHeading.x *= -1;
		}

		newHeading.Normalize();

		entity->setHeading(newHeading);
		entity->setSpeed(WANDERSPEED);

		entity->Move(0.0f);
	}
}
