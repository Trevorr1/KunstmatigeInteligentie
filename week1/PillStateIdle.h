#pragma once
#include "PillState.h"

namespace Tmpl8{
	class PillStateIdle :
		public PillState
	{
	public:
		PillStateIdle();
		virtual ~PillStateIdle();


		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}

