#pragma once
#include "AbstractStateFactory.h"
#include "CowStatePursuit.h"
#include "CowStateWander.h"
#include "CowStateFlee.h"
#include "CowStateHide.h"
#include "CowStateFleePill.h"
#include "CowStateFleeGun.h"
#include "CowStateWander.h"
#include "CowStateIdle.h"
#include "CowStateInvulnerable.h"

namespace Tmpl8{
	class CowStateFactory :
		public AbstractStateFactory
	{
	public:
		static CowStateFactory& getInstance();//use CowStateFactory::getInstance
		virtual ~CowStateFactory();

		EntityState* createState(eState state);

		EntityState* createPursuitState(){ return new CowStatePursuit(); }
		EntityState* createWanderState(){ return new CowStateWander(); }
		EntityState* createFleeState(){ return new CowStateFlee(); }
		EntityState* createHideState(){ return new CowStateHide(); }
		EntityState* createJunkyState(){ return new CowStateFleePill(); }
		EntityState* createGunnerState(){ return new CowStateFleeGun(); }
		EntityState* createIdleState(){ return new CowStateIdle(); }
		EntityState* createInvularableState() { return new CowStateInvulnerable(); }

	private:
		CowStateFactory(){}
	};
}

