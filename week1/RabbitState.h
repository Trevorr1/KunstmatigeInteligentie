#pragma once
#include "EntityState.h"
#include <time.h>

namespace Tmpl8{
	class RabbitState :
		public EntityState
	{
	public:
		RabbitState();
		virtual ~RabbitState();

		void Run(IGameEntity* entity, IGameEntity* other){}
	};
}//namespace Tmpl8

