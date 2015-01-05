#pragma once
#include "AbstractStateFactory.h"
#include "PillStateIdle.h"

namespace Tmpl8{
	class PillStateFactory :
		public AbstractStateFactory
	{
	public:
		static PillStateFactory& getInstance();//use PillStateFactory::getInstance
		virtual ~PillStateFactory();

		EntityState* createState(eState state);

		EntityState* createPursuitState(){ return new PillStateIdle(); }
		EntityState* createWanderState(){ return new PillStateIdle(); }
		EntityState* createFleeState(){ return new PillStateIdle(); }
		EntityState* createHideState(){ return new PillStateIdle(); }
		EntityState* createJunkyState(){ return new PillStateIdle(); }
		EntityState* createGunnerState(){ return new PillStateIdle(); }
		EntityState* createIdleState(){ return new PillStateIdle(); }
		EntityState* createInvularableState() { return new PillStateIdle(); }

	private:

		PillStateFactory(){}
	};
}

