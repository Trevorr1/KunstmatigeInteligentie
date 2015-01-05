#pragma once
#include "AbstractStateFactory.h"
#include "RabbitState.h"
#include "RabbitStateFlee.h"
#include "RabbitStateWander.h"
namespace Tmpl8{
	class RabbitStateFactory :
		public AbstractStateFactory
	{
	public:
		static RabbitStateFactory& getInstance();//use RabbitStateFactory::getInstance
		virtual ~RabbitStateFactory();

		EntityState* createPursuitState() { return new RabbitStateFlee(); };
		EntityState* createWanderState() { return new RabbitStateWander(); }
		EntityState* createFleeState() { return new RabbitStateFlee(); }

	private:
		RabbitStateFactory(){}

	};
}

