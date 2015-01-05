#include "CowStateFactory.h"

using namespace Tmpl8;

CowStateFactory::~CowStateFactory()
{
}

CowStateFactory& CowStateFactory::getInstance()
{
	static CowStateFactory _instance;
	return _instance;
}

EntityState* CowStateFactory::createState(eState state)
{
	switch (state){
	case IDLE:
		return new CowStateWander();
		break;
	case WANDER:
		return new CowStateWander();
		break;
	case HIDE:
		return new CowStateHide();
		break;
	case PURSUIT:
		return new CowStatePursuit();
		break;
	case FLEE:
		return new CowStateFlee();
		break;
	case FLEEPILL:
		return new CowStateFleePill();
		break;
	case FLEEGUN:
		return new CowStateFleeGun();
		break;
	case INVULNERABLE:
		return new CowStateInvulnerable();
		break;
	default:
		return nullptr;
		break;
	}
}
