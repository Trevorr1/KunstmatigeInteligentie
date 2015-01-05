#pragma once
#include "CowState.h"

namespace Tmpl8
{
	class CowStateIdle :
		public CowState
	{
	public:
		CowStateIdle();
		virtual ~CowStateIdle();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral) {}
	};
}//namespace Tmpl8

