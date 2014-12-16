#pragma once
#include "EntityState.h"
namespace Tmpl8{
	class AbstractStateFactory
	{
	public:
		AbstractStateFactory();
		virtual ~AbstractStateFactory();

		virtual EntityState* createPursuitState() = 0;
		virtual EntityState* createWanderState() = 0;
		virtual EntityState* createFleeState() = 0;


	};
}//namespace Tmpl8

