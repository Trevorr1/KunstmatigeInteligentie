#include "RabbitStateFlee.h"
#include "RabbitStateFactory.h"

using namespace Tmpl8;

RabbitStateFlee::RabbitStateFlee()
{
}


RabbitStateFlee::~RabbitStateFlee()
{
}

void RabbitStateFlee::Run(IGameEntity* entity, IGameEntity* other)
{
	float distance = (entity->getPosition() - other->getPosition()).Length();
	if (distance > DANGERRANGE)
	{
		entity->setState(RabbitStateFactory::getInstance().createWanderState());
	}
	else
	{
		//flee code :/
	}
}
