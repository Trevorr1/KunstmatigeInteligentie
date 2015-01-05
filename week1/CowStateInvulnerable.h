#pragma once
#include "CowState.h"

namespace Tmpl8{

	class CowStateInvulnerable :
		public CowState
	{
	public:
		CowStateInvulnerable();
		virtual ~CowStateInvulnerable();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}//namespace Tmpl8

