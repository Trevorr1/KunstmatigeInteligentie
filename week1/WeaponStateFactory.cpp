#include "WeaponStateFactory.h"

using namespace Tmpl8;

WeaponStateFactory& WeaponStateFactory::getInstance()
{
	static WeaponStateFactory _instance;
	return _instance;
}

WeaponStateFactory::~WeaponStateFactory()
{					
}

EntityState* WeaponStateFactory::createState(eState state)
{
	switch (state){
	case IDLE:
		return new WeaponStateIdle();
		break;
	case WANDER:
		return new WeaponStateIdle();
		break;
	case HIDE:
		return new WeaponStateIdle();
		break;
	case PURSUIT:
		return new WeaponStateIdle();
		break;
	case FLEE:
		return new WeaponStateIdle();
		break;
	case FLEEPILL:
		return new WeaponStateIdle();
		break;
	case FLEEGUN:
		return new WeaponStateIdle();
		break;
	case INVULNERABLE:
		return new WeaponStateIdle();
		break;
	default:
		return nullptr;
		break;
	}
}