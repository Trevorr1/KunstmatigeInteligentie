#pragma once
#include "RabbitState.h"


namespace Tmpl8{
	class RabbitStateWander :
		public RabbitState
	{
	public:
		RabbitStateWander();
		virtual ~RabbitStateWander();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}//namespace Tmpl8

