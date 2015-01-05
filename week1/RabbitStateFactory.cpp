#include "RabbitStateFactory.h"

using namespace Tmpl8;


RabbitStateFactory::~RabbitStateFactory()
{
}

RabbitStateFactory& RabbitStateFactory::getInstance()
{
	static RabbitStateFactory _instance;
	return _instance;
}

EntityState* RabbitStateFactory::createState(eState state)
{
	switch (state){
	case IDLE:
		return new RabbitStateWander();
		break;
	case WANDER:
		return new RabbitStateWander();
		break;
	case HIDE:
		return new RabbitStateWander();
		break;
	case PURSUIT:
		return new RabbitStatePursuit();
		break;
	case FLEE:
		return new RabbitStateFlee();
		break;
	case FLEEPILL:
		return new RabbitStateFlee();
		break;
	case FLEEGUN:
		return new RabbitStateFlee();
		break;
	case INVULNERABLE:
		return new RabbitStateWander();
		break;
	default:
		return nullptr;
		break;
	}
}