#pragma once
#include "AbstractStateFactory.h"
#include "WeaponStateIdle.h"

namespace Tmpl8{

	class WeaponStateFactory :
		public AbstractStateFactory
	{
	public:
		static WeaponStateFactory& getInstance();//use WeaponStateFactory::getInstance
		virtual ~WeaponStateFactory();

		EntityState* createState(eState state);

		EntityState* createPursuitState(){ return new WeaponStateIdle(); }
		EntityState* createWanderState(){ return new WeaponStateIdle(); }
		EntityState* createFleeState(){ return new WeaponStateIdle(); }
		EntityState* createHideState(){ return new WeaponStateIdle(); }
		EntityState* createJunkyState(){ return new WeaponStateIdle(); }
		EntityState* createGunnerState(){ return new WeaponStateIdle(); }
		EntityState* createIdleState(){ return new WeaponStateIdle(); }
		EntityState* createInvularableState() { return new WeaponStateIdle(); }

	private:
		WeaponStateFactory(){}
	};
}//namespace Tmpl8

