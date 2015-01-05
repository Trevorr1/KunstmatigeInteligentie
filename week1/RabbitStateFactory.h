#pragma once
#include "AbstractStateFactory.h"
#include "RabbitState.h"
#include "RabbitStateFlee.h"
#include "RabbitStateWander.h"
#include "RabbitStatePursuit.h"
namespace Tmpl8{
	class RabbitStateFactory :
		public AbstractStateFactory
	{
	public:
		static RabbitStateFactory& getInstance();//use RabbitStateFactory::getInstance
		virtual ~RabbitStateFactory();


		EntityState* createState(eState state);

		EntityState* createPursuitState() { return new RabbitStatePursuit(); };
		EntityState* createWanderState() { return new RabbitStateWander(); }
		EntityState* createFleeState() { return new RabbitStateFlee(); }
		EntityState* createHideState()  { return new RabbitStateFlee(); }
		EntityState* createJunkyState(){ return new RabbitStateFlee(); }
		EntityState* createGunnerState() { return new RabbitStateFlee(); }
		EntityState* createIdleState() { return new RabbitStateWander(); }
		EntityState* createInvularableState() { return new RabbitStateWander(); }


		
		

	private:
		RabbitStateFactory(){}

	};
}

