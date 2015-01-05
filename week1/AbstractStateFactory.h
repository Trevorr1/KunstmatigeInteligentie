#pragma once
#include "EntityState.h"
namespace Tmpl8{
	class AbstractStateFactory
	{
	public:
		AbstractStateFactory();
		virtual ~AbstractStateFactory();

		// for easy initialization
		virtual EntityState* createState(eState state) = 0;

		virtual EntityState* createPursuitState() = 0;
		virtual EntityState* createWanderState() = 0;
		virtual EntityState* createFleeState() = 0;
		virtual EntityState* createHideState() = 0;
		virtual EntityState* createJunkyState() = 0;
		virtual EntityState* createGunnerState() = 0;
		virtual EntityState* createIdleState() = 0;
		virtual EntityState* createInvularableState() = 0;


	};
}//namespace Tmpl8

