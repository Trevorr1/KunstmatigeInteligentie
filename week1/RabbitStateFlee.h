#pragma once
#include "RabbitState.h"


namespace Tmpl8{
	class RabbitStateFlee :
		public RabbitState
	{
	public:
		RabbitStateFlee();
		virtual ~RabbitStateFlee();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}//namespace Tmpl8

