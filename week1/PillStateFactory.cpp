#include "PillStateFactory.h"

using namespace Tmpl8;

PillStateFactory& PillStateFactory::getInstance()
{
	static PillStateFactory _instance;
	return _instance;
}

PillStateFactory::~PillStateFactory()
{
}

EntityState* PillStateFactory::createState(eState state)
{
	switch (state){
	case IDLE:
		return new PillStateIdle();
		break;
	case WANDER:
		return new PillStateIdle();
		break;
	case HIDE:
		return new PillStateIdle();
		break;
	case PURSUIT:
		return new PillStateIdle();
		break;
	case FLEE:
		return new PillStateIdle();
		break;
	case FLEEPILL:
		return new PillStateIdle();
		break;
	case FLEEGUN:
		return new PillStateIdle();
		break;
	case INVULNERABLE:
		return new PillStateIdle();
		break;
	default:
		return nullptr;
		break;
	}
}
