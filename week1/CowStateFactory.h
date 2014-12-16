#pragma once
#include "AbstractStateFactory.h"
#include "CowStatePursuit.h"

namespace Tmpl8{
	class CowStateFactory :
		public AbstractStateFactory
	{
	public:
		static CowStateFactory& getInstance();//use CowStateFactory::getInstance
		virtual ~CowStateFactory();

		EntityState* createPursuitState(){ return new CowStatePursuit(); }
		EntityState* createWanderState(){ return new CowStatePursuit(); }
		EntityState* createFleeState(){ return new CowStatePursuit(); }

	private:
		CowStateFactory(){}
	};
}

