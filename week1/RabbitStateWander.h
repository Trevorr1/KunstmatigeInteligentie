#pragma once
#include "RabbitState.h"

#define WANDERSPEED 0.1f

namespace Tmpl8{
	class RabbitStateWander :
		public RabbitState
	{
	public:
		RabbitStateWander();
		virtual ~RabbitStateWander();

		void Run(IGameEntity* entity, IGameEntity* other);
	};
}//namespace Tmpl8

