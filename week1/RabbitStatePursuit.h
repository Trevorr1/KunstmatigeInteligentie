#pragma once
#include "RabbitState.h"
namespace Tmpl8{

	class RabbitStatePursuit :
		public RabbitState
	{
	public:
		RabbitStatePursuit();
		virtual ~RabbitStatePursuit();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}

